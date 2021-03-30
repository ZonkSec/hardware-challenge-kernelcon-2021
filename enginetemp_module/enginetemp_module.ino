const int sensor=A0;
float vout; 

void setup() {
  pinMode(sensor,INPUT); // Configuring sensor pin as input
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(sensor));
  delay(500); 
}
