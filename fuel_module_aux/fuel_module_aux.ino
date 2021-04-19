void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
}

void loop() // run over and over
{
  Serial.print("VLV1-OPEN\r");
  delay(1000);
//  Serial.print("VLV2-OPEN\r");
//  delay(1000);
//  Serial.print("VLV3-OPEN\r");
//  delay(1000);
//  Serial.print("VLV4-OPEN\r");
//  delay(1000);
}
  
