#ifndef base_relay_h_
#define base_relay_h_

#include "base_component.h"

class BaseRelay: public BaseComponent {
  public:
    virtual void receive();
    virtual void emit();
    virtual void send();
};

#endif