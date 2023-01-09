#include <Arduino.h>
#include <KermiteCore.h>
//Libary keyboard_peripheral_modules is also required to run this example
#include <keyboard_peripheral_modules.h>

//example for a keyboard with key matrix, with board LED control

//select an appropriate boardLED initializer for your board
//BoardLED boardLED(25, 25); //pico
//BoardLED boardLED(18, 19, 20, true); //tiny2040
//BoardLED_NeoPixel boardLED(17, 0x40); //kb2040
//BoardLED_NeoPixel boardLED(12, 0x40, 11); //xiao rp2040
//BoardLED_NeoPixel boardLED(16, 0x40); //rp2040-zero
BoardLED_NeoPixel boardLED(25, 0x40); //promicro rp2040

KermiteCore kermite;

//set numColumns, numRows, pinColumns, pinRows according to your board
const int numColumns = 7;
const int numRows = 4;
const int pinColumns[numColumns] = { 28, 27, 26, 22, 20, 23, 21 };
const int pinRows[numRows] = { 6, 7, 8, 9 };

KeyMatrix keyMatrix(pinColumns, pinRows, numColumns, numRows);

int pressedKeyCount = 0;

void handleKeyStateChange(int keyIndex, bool pressed) {
  kermite.feedKeyState(keyIndex, pressed);
  pressedKeyCount += (pressed ? 1 : -1);
  boardLED.write(1, pressedKeyCount > 0);
}

void setup() {
  boardLED.initialize();

  keyMatrix.setKeyStateListener(handleKeyStateChange);
  keyMatrix.initialize();

  kermite.setKeyboardName("mykeeb");
  kermite.begin();
}

void loop() {
  static int count = 0;
  boardLED.write(0, count % 1000 == 0);
  if (count % 10 == 0) {
    keyMatrix.updateInput();
  }
  kermite.processUpdate();
  count++;
  delay(1);
}
