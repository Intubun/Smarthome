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

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
