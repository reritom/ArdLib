#ifndef base_sensor_h_
#define base_sensor_h_

#include "base_component.h"

class BaseSensor: public BaseComponent {
  public:
    virtual void read();
    virtual void callibrate();
};

#endif