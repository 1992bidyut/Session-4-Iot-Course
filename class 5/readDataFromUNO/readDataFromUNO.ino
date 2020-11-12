// include the SoftwareSerial library so you can use its functions:
#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
char cRead;

// set up a new serial port
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()  {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.println("NANO Setup ok");
}

void loop() {
  if (Serial.available()>0){
    cRead=Serial.read();
  mySerial.print(cRead);
 }else{
//  Serial.println("Not available!");
 }
}
