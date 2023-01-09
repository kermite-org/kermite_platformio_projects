#include <Arduino.h>
#include <KermiteCore.h>
//Libary keyboard_peripheral_modules is also required to run this example.
#include <keyboard_peripheral_modules.h>

//single-key keyboard example, with board LED control

//select an appropriate boardLED initializer for your board
//BoardLED boardLED(25, 25); //pico
//BoardLED boardLED(18, 19, 20, true); //tiny2040
BoardLED_NeoPixel boardLED(17, 0x40); //kb2040
//BoardLED_NeoPixel boardLED(12, 0x40, 11); //xiao rp2040
//BoardLED_NeoPixel boardLED(16, 0x40); //rp2040-zero

const int pinButton = 6; //set an input pin for your board

KermiteCore kermite;

void setup() {
  boardLED.initialize();
  pinMode(pinButton, INPUT_PULLUP);
  kermite.setKeyboardName("mykeeb");
  kermite.begin();
}

void loop() {
  static int count = 0;

  bool heartbeat = (count % 1000 == 0);
  boardLED.write(0, heartbeat);

  if (count % 10 == 0) {
    bool pressed = digitalRead(pinButton) == LOW;
    kermite.feedKeyState(0, pressed);
    boardLED.write(1, pressed);
  }
  kermite.processUpdate();
  count++;
  delay(1);
}
