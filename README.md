# kermite_platformio_projects

A collection of examples and development projects for Kermite keyboard firmware with PlatformIO setup.

## Projects Summary

|name | about|
|---|---|
|example_rp2040_basic| simple keyboard with single-key and onboard LED |
|example_rp2040_key_matrix| typical keyboard with keymatrix and onboard LED |
|example_rp2040_minimum| minimum example, single-key keyboard |
|testbed_*| projects under development (detailed below) |

## Project Kind

There are two kind of projects contained in this repository. example projects and testbed projects.

### Example projects

The folders starts with `example_` are ready to use example project. You can create your own firmware project based on these setup.

### Testbed development projects

The folders starts with `testbed_` are projects used to develop and debug KermiteCore. These are in experimental states and maybe unstable.

In order to edit library code easily, local KermiteCore repository is referenced by a symbolic link. Check [./testbed_rp2040/README.md](./testbed_rp2040/README.md) out if you want to build them.

## How to build PlatformIO projects

Here is a brief introduction how to use PlatformIO. 

Although it can be used in command line, it's easier to use VSCode GUI for beginners. If you want to know advanced usage, refer the [official document](https://docs.platformio.org/en/latest/).

### Steps summary

1. Install VSCode (If you don't have)
2. Install PlatformIO extension for VSCode.
3. Open a project folder (witch contains platformio.ini)
4. Execute Build or Upload in the UI at the bottom bar.

### Instruction

VSCode is required. Launch it first.

![install platformio](https://i.gyazo.com/ba5a541092dae8f75cb19dab01ec085d.png)

Open Extensions panel and search PlatformIO, then install it.

![](https://i.gyazo.com/e1f72c5ac0f322cd78b79e64e0f50976.png)

Open a project folder. If we open a folder which includes `platformio.ini`, IDE detects it and shows control UI in status bar.

`platform.ini` is a configuration file to specify the board kind and build settings. Dependent libraries are also maintained here.

![](https://i.gyazo.com/687c9eb8d0337f743542c6d2d443b8d4.png)
Check and modify the code as you need.

 (In the example above, you can change a boardLED declaration and input pin number)

![](https://i.gyazo.com/98107cb542e0aea28b4b9f31ebc25141.png)

To compile and upload the program, it is convenient to use the task buttons in status bar.

Reset the board into bootloader mode before initial upload. 
The port used by a board is automatically detected on uploading. 

![](https://i.gyazo.com/d7ed9504ba6f29a705406df6faa350d5.png)

Upload task executed. Output terminal is open and progress logs are  emitted. Now upload has completed.

Once a firmware uploaded, next time the board is automatically reset, so you don't have to manually reset the board anymore.
