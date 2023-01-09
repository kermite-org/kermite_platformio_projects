
#include <Arduino.h>

extern void appEntry();
extern void app0Entry();

void setup() {
  appEntry();
  // app0Entry();
}

void loop() {}
