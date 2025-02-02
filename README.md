# Thumbsplit60 BLE

Custom designed battery powered fully wireless split keyboard with a display on the right half running ZMK firmware.

![thumbsplit60ble](doc/thumbsplit60ble.jpg)

Thumbsplit60 BLE firmware includes a custom widget to display peripheral (left half) battery and connection status on the central (right half).

TODO: Write display indicator instruction

## Prebuilt Firmware Binaries

You can just download the pre-built firmware binaries to flash here:
- [thumbsplit60ble_left](bin/thumbsplit60ble_left-zmk.uf2)
- [thumbsplit60ble_right](bin/nice_view-thumbsplit60ble_right-zmk.uf2)

Plug your keyboard to the PC with USB and double-click the reset button next to the USB connecter to enter the bootloader. Drag and drop the firmware `uf2` file to the USB flash directory. After finishng file copy, the keyboard will reset automatically with the new firmware.

Note that you have to write left and right firmware separetely to each corresponding half.

## Cutomize Keymap

TODO: Support ZMK Studio

## Building Firwmare

If you want to build the firmware with your customization like advanced keymap changes that ZMK Studio does not support, using GitHub workflow is the easiest way.

Log in to your GitHub account and fork this repository. Then the firmware will be automatically build on GitHub workflow pipeline, and you can download the artifact `firmware.zip` from Actions tab of the repository.

### Local Build Steps

TODO: Write local build instruction