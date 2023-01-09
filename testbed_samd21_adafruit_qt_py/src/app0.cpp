
#include <Arduino.h>
#include <kpm/BoardLED.h>
#include <kpm/SimpleButton.h>

static void boardLedDev() {
  BoardLED boardLED(13, 12, 11);
  boardLED.initialize();
  while (1) {
    boardLED.toggle(0);
    boardLED.toggle(1);
    boardLED.toggle(2);
    delay(1000);
  }
}

static void stdOutTest() {
  pinMode(0, OUTPUT);
  int count = 0;
  while (1) {
    digitalWrite(0, !(digitalRead(0)));
    Serial.printf("Hello %d\n", count);
    count++;
    delay(1000);
  }
}

static void gpioTestOutput() {
  const uint8_t pins[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
  };
  const int numPins = sizeof(pins);

  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
  while (1) {
    for (int i = 0; i < numPins; i++) {
      uint8_t pin = pins[i];
      digitalWrite(pin, !digitalRead(pin));
    }
    delay(100);
  }
}

void app0Entry() {
  boardLedDev();
  // stdOutTest();
  // gpioTestOutput();

  // todo: test uart, i2c, spi, analog io, etc...
}
