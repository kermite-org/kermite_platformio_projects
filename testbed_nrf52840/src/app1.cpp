#include <Arduino.h>
#include <kpm/BoardLED.h>
#include <kpm/SimpleButton.h>

static BoardLED boardLed(11, 12, 13, true);
static SimpleButton button(6);

void app1Entry() {
  boardLed.initialize();

  while (1) {
    boardLed.toggle(0);
    button.update();
    boardLed.write(1, button.hold);
    delay(100);
  }
}
