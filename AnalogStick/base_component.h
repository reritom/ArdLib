#ifndef base_component_h_
#define base_component_h_

class BaseComponent {
  public:
    virtual void setup();
    virtual void loop();
};

#endif