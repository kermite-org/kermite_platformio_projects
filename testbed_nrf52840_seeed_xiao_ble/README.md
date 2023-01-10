# Testbed project for Adafruit Seeed XIAO BLE

## Implementation status

| feature | status |
|-|-|
|USB Keyboard| ok |
|Data Persistence | ok |
|Wireless Connection (BLE)| not implemented yet|

## Storage
Seeed xiao ble has two flash memories. Onchip 1MB flash and external onboard 2MB QSPI flash.
In this porting, external QSPI flash is used to store keymapping.

## Connectivity
Currently, USB HID device features are implemented. Wireless connection is not supported yet.  
