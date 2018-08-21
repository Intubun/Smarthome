


DHT dht(DHT_PIN, DHT_TYPE);

void dht_update(){
  au16data[9] = ((dht.readTemperature()*10)+400);
  au16data[10] = (dht.readHumidity()*10);
  }
