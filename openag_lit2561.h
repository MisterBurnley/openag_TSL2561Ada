#ifndef OPENAG_LIT2561
#define OPENAG_LIT2561


#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_TSL2561_U.h"
#include <openag_module.h>
#include <std_msgs/Int32.h>



class LIT2561 : public Module {
  public:

  Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_LOW, 12345);
  LIT2561 (int i2c_address);
  void configureSensor();
  void begin();
  void update();
  bool get_light_illuminance(std_msgs::Int32 &msg);
  

  private:
  
  bool getEvent(sensors_event_t*);
  void getSensor(sensor_t*);
  bool _send_light_illuminance;  

  void readData();
};

#endif
