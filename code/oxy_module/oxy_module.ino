void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  Serial.print("%OXYGEN_MODULE%OK%33fdd8f3ac0%\r");
  delay(5000);
}
