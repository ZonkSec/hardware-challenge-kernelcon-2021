#include <FreqMeasure.h>
const int led = 10;

void setup() {
  Serial.begin(9600);
  FreqMeasure.begin();
  pinMode(led,OUTPUT);
}

double sum=0;
int count=0;

void loop() {
  if (FreqMeasure.available()) {
    // average several reading together
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count > 30) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      //Serial.println(frequency);
      if (frequency > 5 && frequency < 15) {
        Serial.print("%COMMS_MODULE%OK%a49723307bb%\r");
        digitalWrite(led,HIGH);
      }
      else {
        Serial.println("%COMMS_MODULE%FAULT%\r");
        digitalWrite(led,LOW);
      }
      sum = 0;
      count = 0;
    }
  }
}
