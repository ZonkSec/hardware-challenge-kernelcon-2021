#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int sensor=A7;
float voltage,degreesC;
bool hit = false;

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  pinMode(sensor,INPUT); // Configuring sensor pin as input
  Serial.begin(9600);
  lcd.init();   
  lcd.backlight();
}

void loop() {
  voltage= analogRead(sensor) * (3.3 / 1023.0);
  degreesC = (voltage - 0.5) * 100.0;
  delay(500); 
  
  if ((int)degreesC > 100){
    hit = true;
  }
  if (hit == true){
    lcd.setCursor(0,0);
    lcd.print("TEMP PRIMED!    ");
    lcd.setCursor(0,1);
    lcd.print("STATUS OK       ");

    Serial.print("%TEMP_MODULE%OK%5ce5a69ac3f%\r");
  }
  else{
    
    lcd.setCursor(0,0);
    lcd.print("CURRENT: " + String((int)degreesC)+"C  ");
    lcd.setCursor(0,1);
    lcd.print("TARGET: 100C     ");

    Serial.print("%TEMP_MODULE%FAULT%\r");
  }
}
