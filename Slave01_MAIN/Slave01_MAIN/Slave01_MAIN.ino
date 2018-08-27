
#include "Smart_Settings.h"
#include "Smart_Libarys.h"

void setup() {
  setup_modbus();
  setup_light();
  setup_dht();
  setup_relay();

}

void loop() {
  dht_debug();
  dht_modbus();
  status_led_modbus();
  relay_modbus();
  poll_modbus();
}
