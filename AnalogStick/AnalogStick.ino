#include "joy_stick.h"

void setup(){
  Serial.begin(115200);
  JoyStick joystick(2, 3);
  joystick.setup();
}

void loop() {
  //joystick.loop();
}
