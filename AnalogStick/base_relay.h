#ifndef base_relay_h_
#define base_relay_h_

#include "base_component.h"
#include "base_sensor.h"
#include "base_actuator.h"

class BaseRelay: public BaseComponent {
  public:
    BaseRelay();

    virtual void receive();
    virtual void send();
    void emit();

    void add_sensor(*BaseSensor);
    void add_communicator(*BaseCommunicator);
    void add_actuator(*BaseActuator);

    vector<BaseSensor*> sensors;
    vector<BaseCommunicator*> communicators;
    vector<BaseActuator*> actuators;
};

#endif