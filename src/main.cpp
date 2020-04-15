#include <Arduino.h> //Se incluyen las librerías necesarias
#include <WiFi.h>
#include <MQTT.h>
#include <llp.h>
#include <constants.h>
#include <connect.h>
#include <DHTsensor.h>
#include "DHT.h"



DataPack input = DataPack();
DHTsensor sensor = DHTsensor(0x76, 1, 500);

WiFiClient net;      
MQTTClient client;




long reportTimer = millis();  //Se declara un valor inicial para el timer

void setup() {
    Serial.begin(115200);   //Se inicializa Serial, wifi y broker
    WiFi.begin(SSID, SSID_PASSWORD);
    client.begin(BROKER, net);
    connect(Serial, net, client);
    sensor.init(pin);
    dht.begin();
}

void loop() {

  client.loop();
  delay(10);

  if (!client.connected()) {     //Para reconectar
    connect(Serial, net, client);
  }
  if(millis()-reportTimer >= REPORT_FREQ){
    reportTimer=millis();
    if (sensor.hasChange()){
      // client.publish(String(MQTT_ID)+"/report", String(sensor.read()));
      client.publish(String(MQTT_ID)+"/temperatura", "{\"temperature\":" +  String(sensor.readtemp()) + "}");
      client.publish(String(MQTT_ID)+"/humedad", "{\"humidity\":" +  String(sensor.readhum()) + "}");
    }
  Serial.println(sensor.readtemp());
  }
}