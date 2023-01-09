#include <Arduino.h>
#include <KermiteCore.h>
#include <kpm/BoardLED.h>
#include <kpm/SimpleButton.h>
//workaround for LDF
#include <Adafruit_NeoPixel.h>
#include <Adafruit_TinyUSB.h>

BoardLED boardLED(13, 12, 11, true);
static SimpleButton button(6);

static KermiteCore kermite;

static void updateButton() {
  button.update();
  bool pressed = button.hold;
  kermite.feedKeyState(0, pressed);
  boardLED.write(1, pressed);
}

void appEntry() {
  boardLED.initialize();

  kermite.setFlashSavingWaitTimeSec(20);
  kermite.setKeyboardName("mykeeb");
  kermite.enableDebugLogging();

  boardLED.write(0, true);
  kermite.begin();
  boardLED.write(0, false);

  int count = 0;
  while (1) {
    bool heartbeat = (count % 1000 == 0);
    boardLED.write(0, heartbeat);
    if (count % 10 == 0) {
      updateButton();
    }
    kermite.processUpdate();
    count++;
    yield();
    delay(1);
  }
}
