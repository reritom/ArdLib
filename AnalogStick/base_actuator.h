#ifndef base_actuator_h_
#define base_actuator_h_

#include "base_component.h"

class BaseActuator: public BaseComponent {
  public:
    virtual void actuate();
};

#endif