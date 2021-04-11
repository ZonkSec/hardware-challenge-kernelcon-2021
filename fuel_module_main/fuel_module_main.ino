#include <SoftwareSerial.h>
String input;
bool vlv1 = false;
bool vlv2 = false;
bool vlv3 = false;
bool vlv4 = false;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

SoftwareSerial mySerial(3, 2); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() // run over and over
{
  if (mySerial.available()){
    input ="";
    input = mySerial.readStringUntil('\r');
    if (input == "VLV1-OPEN"){
      digitalWrite(led1,HIGH);
      mySerial.println("VALVE 1 OPENED");
      vlv1 = true;
    }
    if (input == "VLV2-OPEN"){
      digitalWrite(led2,HIGH);
      mySerial.println("VALVE 2 OPENED");
      vlv2 = true;
    }
    if (input == "VLV3-OPEN"){
      digitalWrite(led3,HIGH);
      mySerial.println("VALVE 3 OPENED");
      vlv3 = true;
    }
    if (input == "VLV4-OPEN"){
      digitalWrite(led4,HIGH);
      mySerial.println("VALVE 4 OPENED");
      vlv4 = true;
    }
    if (input == "VLV1-CLOSE"){
      digitalWrite(led1,LOW);
      mySerial.println("VALVE 1 CLOSED");
      vlv1 = false;
    }
    if (input == "VLV2-CLOSE"){
      digitalWrite(led2,LOW);
      mySerial.println("VALVE 2 CLOSED");
      vlv2 = false;
    }
    if (input == "VLV3-CLOSE"){
      digitalWrite(led3,LOW);
      mySerial.println("VALVE 3 CLOSED");
      vlv3 = false;
    }
    if (input == "VLV4-CLOSE"){
      digitalWrite(led4,LOW);
      mySerial.println("VALVE 4 CLOSED");
      vlv4 = false;
    }
    if (vlv1 && vlv2 && vlv3 && vlv4){
      Serial.print("%FUEL_MODULE%OK%123456abcdf%\r");
    }
    else{
      Serial.print("%FUEL_MODULE%FAULT%\r");
    }
  }
  else{
    if (vlv1 && vlv2 && vlv3 && vlv4){
      Serial.print("%FUEL_MODULE%OK%3b429d7e669%\r");
    }
    else{
      Serial.print("%FUEL_MODULE%FAULT%\r");
    }
  }
  delay(1000);
}
  
