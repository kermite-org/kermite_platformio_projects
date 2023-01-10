# Testbed project for RP2040 boards

This project is intended to be used for development and debugging KermiteCore.

The application is a simple keyboard with one-key and one-LED. It is used to check the developing core library works correctly.

## Setup

The library code is referenced by symlink. It is required to have a symbolic link `./lib/kermite_core_arduino/src` points to `<RepositoryRoot>/../KermiteCore_Arduino/src`.
To setup this, run
```
  make symlink_win_create
```
for Windows or
```
  make symlink_mac_create
```
for MacOS.

## Configurations (`app.cpp`)

In `src/app.cpp`, there is a LED and button configurations part. please change them according to your board.

```c
static BoardLED boardLED(25); //pico
// static BoardLED boardLED(18, 19, 20, true); //tiny2040
// static BoardLED_NeoPixel boardLED(17, 0x40); //kb2040
// static BoardLED_NeoPixel boardLED(12, 0x40, 11); //xiao rp2040
// ...

static SimpleButton button(6); //set an input pin for your board
```

## Build and debug

To build and write the firmware to the board, execute
```
  pio run --target upload
``` 
  or simply 
```
  make flash
```


## Implementation status

for RP2040

| feature | status |
|-|-|
|USB Keyboard| ok |
|Data Persistence | ok |

There are two usb device implementation. arduino-pico's default usb stack based and Adafruit_TinyUSB based. It is recommended to use Adafruit_TinyUSB based implementation since this is more configurable. To enable this, add the lines below in `platformio.ini`.
```ini
  build_flags = -DUSE_TINYUSB -DCFG_TUD_HID=2
```

## Notes
In platformio.ini, you can specify the target board.

`board = generic` can be used for any boards.

`board = pico` is not supported. With this configuration, mbed based framework is used instead of arduino-pico.
