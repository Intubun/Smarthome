DHT dht(DHT_PIN, DHT_TYPE);

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
