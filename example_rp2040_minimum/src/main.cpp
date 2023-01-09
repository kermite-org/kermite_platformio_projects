#include <Arduino.h>
#include <KermiteCore.h>

//minimum single-key keyboard example

KermiteCore kermite;
int pinButton = 6; //set the pin connected to a key

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  kermite.setKeyboardName("mykeeb");
  kermite.begin();
}

void loop() {
  static int count = 0;

  if (count % 10 == 0) {
    bool pressed = digitalRead(pinButton) == LOW;
    kermite.feedKeyState(0, pressed);
  }
  kermite.processUpdate();
  count++;
  delay(1);
}
