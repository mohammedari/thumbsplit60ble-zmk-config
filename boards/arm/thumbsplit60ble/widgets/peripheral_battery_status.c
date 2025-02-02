/*
 * Copyright (c) 2025 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "peripheral_battery_status.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/split_peripheral_status_changed.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

// TODO should be configurable
#define PERIPHERAL_SOURCE_INDEX (0)

struct peripheral_battery_status_state {
    uint8_t level;
    bool connected;
};

// TODO should re-use the function in battery_status.c
static void set_battery_symbol(lv_obj_t *label, struct peripheral_battery_status_state state) {
    char text[9] = {};

    if (state.connected) {
        uint8_t level = state.level;

#if IS_ENABLED(CONFIG_ZMK_WIDGET_peripheral_battery_status_SHOW_PERCENTAGE)
        char perc[5] = {};
        snprintf(perc, sizeof(perc), "%3u%%", level);
        strcat(text, perc);
#else
        if (level > 95) {
            strcat(text, LV_SYMBOL_BATTERY_FULL);
        } else if (level > 65) {
            strcat(text, LV_SYMBOL_BATTERY_3);
        } else if (level > 35) {
            strcat(text, LV_SYMBOL_BATTERY_2);
        } else if (level > 5) {
            strcat(text, LV_SYMBOL_BATTERY_1);
        } else {
            strcat(text, LV_SYMBOL_BATTERY_EMPTY);
        }
#endif
    } else {
        strcat(text, LV_SYMBOL_CLOSE);
    }

    lv_label_set_text(label, text);
}

void peripheral_battery_status_update_cb(struct peripheral_battery_status_state state) {
    struct zmk_widget_peripheral_battery_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_symbol(widget->obj, state); }
}

static struct peripheral_battery_status_state
peripheral_battery_status_get_state(const zmk_event_t *eh) {
    uint8_t level;
    int rc = zmk_split_get_peripheral_battery_level(PERIPHERAL_SOURCE_INDEX, &level);

    LOG_DBG("Peripheral battery level %d fetched with return code %d", level, rc);

    return (struct peripheral_battery_status_state){
        .level = level,
        .connected = rc == 0,
    };
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_peripheral_battery_status,
                            struct peripheral_battery_status_state,
                            peripheral_battery_status_update_cb,
                            peripheral_battery_status_get_state);

ZMK_SUBSCRIPTION(widget_peripheral_battery_status, zmk_peripheral_battery_state_changed);
ZMK_SUBSCRIPTION(widget_peripheral_battery_status, zmk_split_peripheral_status_changed);

int zmk_widget_peripheral_battery_status_init(struct zmk_widget_peripheral_battery_status *widget,
                                              lv_obj_t *parent) {
    widget->obj = lv_label_create(parent);

    sys_slist_append(&widgets, &widget->node);

    widget_peripheral_battery_status_init();
    return 0;
}

lv_obj_t *
zmk_widget_peripheral_battery_status_obj(struct zmk_widget_peripheral_battery_status *widget) {
    return widget->obj;
}
