#include "openag_lit2561.h"


LIT2561::LIT2561(int i2c_address) {

}

void LIT2561::configureSensor() {

  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
  tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  //tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  //tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */

}


void LIT2561::begin() {

  Serial.begin(9600);
  tsl.begin();
  configureSensor();


}

void LIT2561::update() {

//Read from the sensor

  sensors_event_t event;
  tsl.getEvent(&event);
  if (event.light) {
  _send_light_illuminance = true;
  }
  else {
  begin();
  }
  delay(1000);

}

bool LIT2561::get_light_illuminance(std_msgs::Int32 &msg) {

  sensors_event_t event;
  tsl.getEvent(&event);
  msg.data = (event.light);
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

