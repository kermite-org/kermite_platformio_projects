#include <Arduino.h>
#include <KermiteCore.h>
#include <kpm/BoardLED_NeoPixel.h>
#include <kpm/SimpleButton.h>

static BoardLED_NeoPixel boardLED(11, 0x40);
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
  // kermite.setProductionMode();

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
