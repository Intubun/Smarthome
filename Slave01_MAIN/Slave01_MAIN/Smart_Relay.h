void setup_relay() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  }

void relay_modbus() {
  digitalWrite(R1, bitRead(au16data[RELAY_R], 0));
  digitalWrite(R2, bitRead(au16data[RELAY_R], 1));
  digitalWrite(R3, bitRead(au16data[RELAY_R], 2));
  digitalWrite(R4, bitRead(au16data[RELAY_R], 3));
  digitalWrite(R5, bitRead(au16data[RELAY_R], 4));
  digitalWrite(R6, bitRead(au16data[RELAY_R], 5));
  digitalWrite(R7, bitRead(au16data[RELAY_R], 6));
  digitalWrite(R8, bitRead(au16data[RELAY_R], 7));
  }
