#include <Arduino.h> //Se incluyen las librerías necesarias
#include <WiFi.h>
#include <MQTT.h>

#include <constants.h>
#include <connect.h>


WiFiClient net;      
MQTTClient client;

long reportTimer = millis();  //Se declara un valor inicial para el timer

void setup() {

    Serial.begin(115200);   //Se inicializa Serial, wifi y broker
    WiFi.begin(SSID, SSID_PASSWORD);
    client.begin(BROKER, net);
    connect(Serial, net, client);
}

void loop() {
  client.loop();
  delay(10);
  
  if (!client.connected()) {     //Para reconectar
    connect(Serial, net, client);
  }
  if(millis()-reportTimer >= REPORT_FREQ){
    reportTimer=millis();
    client.publish(String(MQTT_ID)+"/report", String(analogRead(A3)));
    Serial.println(analogRead(A3));
  }

}