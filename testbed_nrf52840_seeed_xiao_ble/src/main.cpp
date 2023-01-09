#include <Arduino.h>

extern void appEntry();
extern void app0Entry();
extern void app1Entry();

void setup() {
  appEntry();
  // app0Entry();
  // app1Entry();
}

void loop() {}
