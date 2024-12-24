# Thumbsplit60 BLE

Custom designed battery powered fully wireless split keyboard with a display on the right half running ZMK firmware.

## Build & Flash Firmware

After following official ZMK setup, you can type following commands in `app` directory to build.
```
west build -p -b thumbsplit60ble_right -S studio-rpc-usb-uart -d build/right -- -DCONFIG_ZMK_STUDIO=y -DSHIELD=nice_view
west build -p -b thumbsplit60ble_left  -S studio-rpc-usb-uart -d build/left  -- -DCONFIG_ZMK_STUDIO=y
```

Double click reset button of the keyboard and drag and drop `app/build/left/zmk.uf2` for left and `app/build/right/zmk.uf2` for right.

## Tips

### FAILED: nanopb/generator/proto/nanopb_pb2.py /workspaces/zmk/app/build/right/nanopb/generator/proto/nanopb_pb2.py

Please make sure to set autocrlf to `input` in this repository as the file is processed through devcontainer in VSCode.
```
git config core.autocrlf input
```

If the file `nanopb.proto` is already converted to 'CRLF' format by autocrlf, you can make sure to keep local changes and clone the repository again. 

