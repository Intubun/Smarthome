/*

Dies ist der Slave-Script der für den Arduino-Mega geschrieben ist.



copyright by Enno Schnackenberg
*/
#include <DHT.h>
#include <ModbusRtu.h>
#define TXEN  2 
#define ID 1                                    //definiere alle fürn Modbus relevante Variablen
#define BUS 1
uint16_t au16data[64] = {0};                    //baue das Daten-Array für den Modbus
Modbus slave(ID,BUS,TXEN);


#define DHTPIN 3
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  slave.begin(9600);                          //beginne die Modbus Datenverbinding
  io_set();
}

void loop() {
  slave.poll(au16data, 64);                     //stelle die daten zur verfügung / hole dir die daten
  dht_debug();
  float h = dht.readHumidity(); 
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Fehler! DHT Sensor konnte nicht ausgelesen werden!");
    return;}
  digitalWrite(13, bitRead(au16data[0], 0));    //schreibe die Status-LED

}

void io_setup() {
  pinMode(13, OUTPUT);                          //definiere die Status-LED

  }













