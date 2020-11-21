
#include<ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "BONYOSHOVA";
const char* password = "1992199419951996";

const char* mqtt_server="192.168.1.11";
WiFiClient espClient;
PubSubClient client(espClient);

long now = millis();
long lastTime=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Device IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server,1883);
  client.setCallback(callBack);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
    reconnect();
  }
  if(!client.loop()){
    client.connect("ESP8266Client");
  }
  sendDataToMQTT();
}

void reconnect(){
  while(!client.connected()){
    Serial.println("Server connecting....");
    if(client.connect("ESP8266Client")){
      Serial.println("Server connected");
      client.subscribe("lamp");
      client.subscribe("fan");
    }else{
      Serial.println("Failed to connected");
      delay(500);
    }
  }
}
//send to MQTT
int counter=0;
void sendDataToMQTT(){
  now=millis();
  if(now-lastTime>3000){
    lastTime=now;
    static char count[7];
    itoa(counter,count,7);
    client.publish("count",count);
    counter++;
    if(counter==100)
    counter=0;
  }
}

//MQTT_SUB
void callBack(String topic,byte*message, unsigned int length){
  Serial.print("Topic: ");
  Serial.println(topic);
  String strMsg;
  for(int i=0;i<length;i++){
    strMsg+= (char)message[i];
  }
  Serial.print("Message: ");
  Serial.println(strMsg);
}
