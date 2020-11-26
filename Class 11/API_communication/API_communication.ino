#include<Arduino.h>
#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
#include<ESP8266HTTPClient.h>
#include<WiFiClient.h>
#include<ArduinoJson.h>

ESP8266WiFiMulti WiFiMulti;
String uname="divine@iot.com";
String upass="abcd";
String deviceId="iotc31654";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFiMulti.addAP("BONYOSHOVA","1992199419951996");
}

void loop() {
  if(WiFiMulti.run()==WL_CONNECTED){
    //httpGETRequest();
    httpPOSTRequest();
    delay(3000);
  }
  yield();
}

void httpGETRequest(){
  HTTPClient http;
  String url="http://192.168.1.9/devine_it/S3/api_module/get_switch_status.php?uname="+uname+"&upass="+upass;
  http.begin(url);
  int requestCode=http.GET();
  if(requestCode>0){
    Serial.print("Request Code: ");
    Serial.println(requestCode);
    String response=http.getString();
    Serial.println(response);
    jsonGETDecoder(response);
  }
  yield();
}

void httpPOSTRequest(){
  HTTPClient http;
  String url="http://192.168.1.9/devine_it/S3/api_module/pull_switch_state.php";

  StaticJsonDocument<300> requestDoc;
  requestDoc["uname"]=uname;
  requestDoc["upass"]=upass;
  requestDoc["deviceId"]=deviceId;

  char JSONmessagerBuffer[300];
  serializeJson(requestDoc,JSONmessagerBuffer);
  Serial.print("Request Body: ");
  Serial.println(JSONmessagerBuffer);
  
  http.begin(url);
  http.addHeader("Content-Type","application/json");
  int requestCode=http.POST(JSONmessagerBuffer);
  if(requestCode>0){
    Serial.print("Request Code: ");
    Serial.println(requestCode);
    String response=http.getString();
    Serial.println(response);
    jsonPOSTDecoder(response);
  }
yield();
}

void jsonGETDecoder(String response){
  const size_t bufferSize=JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(5)+200;
  DynamicJsonDocument resDoc(bufferSize);
  DeserializationError error=deserializeJson(resDoc,response);
  
  if(error){
    Serial.println("Error at JSON decode!");
    return;
  }
  const char* value1=resDoc["iotba27"];
  
  if(String(value1)=="1"){
    Serial.print("On Value1: ");
    Serial.println(value1);
  }else{
    Serial.print("Off Value1: ");
    Serial.println(value1);
  }
 }

 void jsonPOSTDecoder(String response){
  const size_t bufferSize=JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(5)+200;
  DynamicJsonDocument resDoc(bufferSize);
  DeserializationError error=deserializeJson(resDoc,response);
  
  if(error){
    Serial.println("Error at JSON decode!");
    return;
  }
  const char* value1=resDoc["iotc31654"];
  
  if(String(value1)=="1"){
    Serial.print("On Value1: ");
    Serial.println(value1);
  }else{
    Serial.print("Off Value1: ");
    Serial.println(value1);
  }
 }
