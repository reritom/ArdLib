#include "joy_stick.h"
#include <Arduino.h>

JoyStick::JoyStick(int x_attach, int y_attach){
  x_pin = x_attach;
  y_pin = y_attach;
}

void JoyStick::loop(){
  Serial.println("In loop");
}

void JoyStick::read() {
  Serial.println("Reading");
}

void JoyStick::callibrate() {
  // For 10 seconds we read the values of each input to determine the max and min amounts
  // The user is expected to move the joystick in a circular fashion
  Serial.print("Running callibration");

  unsigned long mid_callibration_period = 2 * 1000; // milliseconds
  unsigned long mm_callibration_period = 10 * 1000; // milliseconds

  unsigned long start_time = millis();
  unsigned long current_time = start_time;

  // Mid callibration
  unsigned long x_mid_sum = 0;
  unsigned long x_mid_count = 0;
  unsigned long y_mid_sum = 0;
  unsigned long y_mid_count = 0;

  while (current_time < start_time + mid_callibration_period) {
    x_mid_sum += analogRead(x_pin);
    ++x_mid_count;

    y_mid_sum += analogRead(y_pin);
    ++y_mid_count;

    current_time = millis();
  }

  // Calclulate the averages
  x_mid = x_mid_sum / x_mid_count;
  y_mid = y_mid_sum / y_mid_count;

  // Max and Min callibration

  // Set them to a middle value begin
  x_min = x_max = y_min = y_max = 500;

  // Reset the start time for the next callibration cycle
  start_time = millis();

  while (current_time < start_time + mm_callibration_period) {
    // Get the X
    int this_x = analogRead(x_pin);
    if (this_x > x_max) {
      x_max = this_x;
    }
    else if (this_x < x_min) {
      Serial.print(x_min);
      Serial.print(" ");
      Serial.println(this_x);
      x_min = this_x;
    }

    // Get the Y
    int this_y = analogRead(y_pin);
    if (this_y > y_max) {
      y_max = this_y;
    }
    else if (this_y < y_min) {
      y_min = this_y;
    }

    current_time = millis();
  }

  delay(5000);
}

void JoyStick::setup(){
  callibrate();
}
