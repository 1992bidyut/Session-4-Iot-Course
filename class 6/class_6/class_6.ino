#include <SoftwareSerial.h>
#define rxPin 8
#define txPin 9
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
int val=0;
double voltage=0.0;
int angVal=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("UNO Setup ok");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5)==LOW){
    digitalWrite(6,HIGH);
    mySerial.println("Switch ON from UNO");
  }else{
    digitalWrite(6,LOW);
    mySerial.println("Switch OFF from UNO");
  }
  val=analogRead(A0);
  voltage=(val*0.0048828125)*10;
  Serial.println(voltage);
  analogWrite(11,angVal);
  delay(1000);
  if(angVal>=255){
    angVal=0;
  }
  angVal=angVal+20;
}
