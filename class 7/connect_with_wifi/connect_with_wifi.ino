#include <Arduino.h>
#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
#include<WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char* SSID = "Lareye.com";
const char* PASSWORD ="lareye@2020";

ESP8266WiFiMulti WifiMulti;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WifiMulti.addAP(SSID,PASSWORD);

  while(WifiMulti.run()!= WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WifiMulti.run()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    http.begin(client,"http://jigsaw.w3.org/HTTP/connection.html");
    int resCode = http.GET();
    Serial.print("Code: ");
    Serial.println(resCode);
    if(resCode==200){
      String payload = http.getString();
      Serial.println("Response: ");
      Serial.println(payload);
    }
  }
  delay(5000);
}
