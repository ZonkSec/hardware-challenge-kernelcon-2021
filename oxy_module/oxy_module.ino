void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  Serial.print("%OXYGEN_MODULE%OK%123456abcdf%\r");
  delay(5000);
}
