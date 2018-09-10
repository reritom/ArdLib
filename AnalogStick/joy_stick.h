#ifndef joy_stick_h_
#define joy_stick_h_

#include "base_sensor.h"

class JoyStick: public BaseSensor {
  public:
    JoyStick(int x_attach, int y_attach);
    void setup();
    void loop();
    void callibrate();
    void read();

    int x_pin;
    int y_pin;

  protected:
    int x_max;
    int x_mid;
    int x_min;

    int y_max;
    int y_mid;
    int y_min;
};

#endif
