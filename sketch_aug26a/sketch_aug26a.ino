#include <DHT.h>
#include <ModbusRtu.h>

#define DHT_PIN 3               //it is the pin which is connectet at the DHT
#define DHT_TYPE DHT22          //it is the the type of the DHT
#define TEMP_R 9                //it is the temperature register
#define HUDM_R 10               //it is the humidity register

#define REGISTER 64             //it is the number of register 
#define BUS 1                   //it is the bus where the modbus is sending at the Arduino MEGA
#define TXEN 2                  //it it transmit and recive pin
#define ADR 1                   //it is the Adress of the slave
#define BAUD 9600               //it is the bits per second Rate

#define Status_LED 13           //it is the internal LED of the Arduino
#define LED_R 0                  //it is the LED register

#define RELAY_R 2               //it is the relay register
#define R1 23                   
#define R2 25
#define R3 27
#define R4 29                   //Thats are the
#define R5 31                   //pin from the relays
#define R6 33
#define R7 35
#define R8 37

DHT dht(DHT_PIN, DHT_TYPE);

uint16_t au16data[REGISTER] = {0};
Modbus slave(ADR,BUS,TXEN);

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
void dht_modbus(){
  au16data[TEMP_R] = ((dht.readTemperature()*10)+400);
  au16data[HUDM_R] = (dht.readHumidity()*10);
  }

void setup_dht() {
  dht.begin();
  }

void dht_debug() {
  if (isnan(dht.readTemperature()) || isnan(dht.readHumidity())) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    }
  }
  
void setup_light() {
  pinMode(Status_LED, OUTPUT);
  }

void status_led_modbus() {
  digitalWrite(Status_LED, bitRead(au16data[LED_R], 0));
  }

void setup_modbus() {
  slave.begin(BAUD);
  }

void poll_modbus() {
  slave.poll();
  }

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
