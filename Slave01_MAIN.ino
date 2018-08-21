#include "Smart_Settings.h"
#include "Smart_Libarys.h"

void setup() {
  setup_modbus();
  setup_light();
  setup_dht();
  setup_relay();

}

void loop() {
  // put your main code here, to run repeatedly:

}
