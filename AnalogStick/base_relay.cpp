#include "base_relay.h"

BaseRelay::BaseRelay() {

}

void BaseRelay::add_sensor(*BaseSensor sensor) {
  sensors.push_back(sensor);
}

void BaseRelay::add_communicator(*BaseCommunicator communicator){
  communicators.push_back(communicator)
}

void BaseRelay::add_actuator(*BaseActuator actuators){
  actuators.push_back(actuator);
}

void BaseRelay::send(){

}

void BaseRelay::retrieve() {

}
