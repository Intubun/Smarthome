uint16_t au16data[REGISTER] = {0};
Modbus slave(ADR,BUS,TXEN);

void setup_modbus() {
  slave.begin(BAUD);
  }

void poll_modbus() {
  slave.poll();
  }
