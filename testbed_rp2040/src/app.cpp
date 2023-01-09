#include <Arduino.h>
#include <KermiteCore.h>
#include <kpm/BoardLED.h>
#include <kpm/BoardLED_NeoPixel.h>
#include <kpm/SimpleButton.h>

// static BoardLED boardLED(25); //pico
// static BoardLED boardLED(18, 19, 20, true); //tiny2040
static BoardLED_NeoPixel boardLED(17, 0x40); //kb2040
// static BoardLED_NeoPixel boardLED(12, 0x40, 11); //xiao rp2040
// static BoardLED_NeoPixel boardLED(16, 0x40); //rp2040-zero
// static BoardLED_NeoPixel boardLED(12, 0x40, 11); //qt py rp2040
// static BoardLED_NeoPixel boardLED(25, 0x40); //promicro rp2040
// static BoardLED_NeoPixel boardLED(23, 0x40); //yd-rp2040

static SimpleButton button(6); //set an input pin for your board

static KermiteCore kermite;
static bool pressed;

static void updateButton() {
  button.update();
  pressed = button.hold;
  kermite.feedKeyState(0, pressed);
}

void appEntry() {
  boardLED.initialize();

  kermite.setKeyboardName("mykeeb");
  kermite.enableDebugLogging();

  boardLED.write(0, true);
  kermite.begin();
  boardLED.write(0, false);

  int cnt = 0;
  while (1) {
    bool heartbeat = (cnt % 1000 == 0);
    boardLED.write(0, heartbeat || pressed);
    if (cnt % 10 == 0) {
      updateButton();
    }
    kermite.processUpdate();
    cnt++;
    yield();
    delay(1);
  }
}
