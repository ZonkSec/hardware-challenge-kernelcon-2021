void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("%OXYGEN_MODULE%OK%123456abcdf%");
  delay(5000);
}
