# Thumbsplit60 BLE

Custom designed battery powered fully wireless split keyboard with a display on the right half running ZMK firmware.

## Build & Flash Firmware

After following official ZMK setup, 
```
west init -l app/
west update
```

you can type following commands in `app` directory to build.
```
west build -p -b thumbsplit60ble_right -d build/right -- -DSHIELD=nice_view
west build -p -b thumbsplit60ble_left  -d build/left  -- 
```

Double click reset button of the keyboard and drag and drop `app/build/left/zephyr/zmk.uf2` for left and `app/build/right/zephyr/zmk.uf2` for right.

### Note on ZMK Studio Support

If you wish supporting ZMK Studio, you can build with thw following command.
```
west build -p -b thumbsplit60ble_right -S studio-rpc-usb-uart -d build/right -- -DCONFIG_ZMK_STUDIO=y -DSHIELD=nice_view
west build -p -b thumbsplit60ble_left  -S studio-rpc-usb-uart -d build/left  -- -DCONFIG_ZMK_STUDIO=y
```

However, Windows environment may cause the following error. You have to parepare another environment other than Windows to build with ZMK support.
TODO: confirm that changing git checkout configuration to as-is may solve this issue
```
[42/558] Generating nanopb/generator/proto/nanopb_pb2.py
FAILED: nanopb/generator/proto/nanopb_pb2.py /workspaces/zmk2/app/build/right/nanopb/generator/proto/nanopb_pb2.py 
cd /workspaces/zmk2/app/build/right && /workspaces/zmk2/modules/lib/nanopb/generator/protoc -I/workspaces/zmk2/app/build/right/nanopb/generator/proto --python_out=/workspaces/zmk2/app/build/right/nanopb/generator/proto /workspaces/zmk2/app/build/right/nanopb/generator/proto/nanopb.proto
/usr/bin/env: 'python3\r': No such file or directory
/usr/bin/env: use -[v]S to pass options in shebang lines
[59/558] Building C object zephyr/CMakeFiles/zephyr.dir/subsys/usb/device/usb_device.c.obj
ninja: build stopped: subcommand failed.
FATAL ERROR: command exited with status 1: /usr/local/bin/cmake --build /workspaces/zmk2/app/build/right
```
