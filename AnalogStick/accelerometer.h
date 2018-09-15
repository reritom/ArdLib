#ifndef accelerometer_h_
#define accelerometer_h_

#include "base_sensor.h"

class Accelerometer: public BaseSensor {
  public:
    int sda_pin;
    int scl_pin;
};

#endif