# Thumbsplit60 BLE

Custom designed battery powered fully wireless split keyboard with a display on the right half running ZMK firmware.

## Build & Flash Firmware

After following official ZMK setup, you can type following commands to build.
```
west build -p -b thumbsplit60ble_right -d build/right -- -DSHIELD=nice_view
west build -p -b thumbsplit60ble_left -d build/left -- -DSHIELD=nice_view
```

Double click reset button of the keyboard and drag and drop `app/build/left/zmk.uf2` for left and `app/build/right/zmk.uf2` for right.
