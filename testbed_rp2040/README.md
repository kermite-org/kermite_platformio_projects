# Testbed project for KermiteCore

This project is intended to be used for development and debugging KermiteCore.

The application is a simple keyboard with one-key and one-LED. It is used to check the developing core library works correctly.


## Setup

The library code is referenced by symlink. It is required to have a symbolic link `./lib/KermiteCore_Arduino` points to `<RepositoryRoot>/../KermiteCore_Arduino`.
To setup this, run
```
  make symlink_win_create
```
for Windows or
```
  make symlink_mac_create
```
for MacOS.


## Configurations (`platformio.ini`)

There is 2 configuration targets in platformio.ini.
- `[env:generic]` is used for normal development.
- `[env:portable_stack]` is a special setting which uses portable version of the hardware dependent modules.

You can select default build target by comment-in the declaration `default_envs=...`.
```ini
[platformio]
default_envs=generic
;default_envs=portable_stack
```

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

