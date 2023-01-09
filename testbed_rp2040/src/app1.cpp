#include <Arduino.h>
#include <KermiteCore.h>
#include <kpm/BoardLED_NeoPixel.h>
#include <kpm/KeyMatrix.h>

KermiteCore kermite;

BoardLED_NeoPixel boardLED(25, 0x40); //promicro rp2040

const int numColumns = 7;
const int numRows = 4;
const int pinColumns[numColumns] = { 28, 27, 26, 22, 20, 23, 21 };
const int pinRows[numRows] = { 6, 7, 8, 9 };

KeyMatrix keyMatrix(pinColumns, pinRows, numColumns, numRows);

int pressedKeyCount = 0;

void handleKeyStateChange(int keyIndex, bool pressed) {
  kermite.feedKeyState(keyIndex, pressed);
  pressedKeyCount += (pressed ? 1 : -1);
}

void app1Entry() {
  boardLED.initialize();

  keyMatrix.setKeyStateListener(handleKeyStateChange);
  keyMatrix.initialize();

  kermite.setKeyboardName("mykeeb");
  kermite.enableDebugLogging();
  kermite.begin();

  int count = 0;
  while (1) {
    boardLED.write(0, count % 2000 == 0);
    if (count % 10 == 0) {
      keyMatrix.updateInput();
      boardLED.write(2, pressedKeyCount > 0);
    }
    kermite.processUpdate();
    count++;
    delay(1);
    yield();
  }
}
