#include <Wire.h>     // for I2C
 
#define eeprom_address 0x50    // device address 
byte d=0;
 
void setup()
{
  Serial.begin(9600); // Initialize the serial
  Wire.begin();
 
  //write data out
//  Serial.println("Writing data.");
//  writeData(0,0x4c); //L
//  writeData(1,0x41); //A
//  writeData(2,0x55); //U
//  writeData(3,0x4e); //N
//  writeData(4,0x43); //C
//  writeData(5,0x48); //H
//  writeData(6,0x20); //space
//  writeData(7,0x43); //C
//  writeData(8,0x4f); //O
//  writeData(9,0x44); //D
//  writeData(10,0x45); //E
//  writeData(11,0x3a); //:
//  writeData(12,0x20); //space
//  writeData(13,0x4c); //L
//  writeData(14,0x65); //e
//  writeData(15,0x74); //t
//  writeData(16,0x73); //s
//  writeData(17,0x50); //P
//  writeData(18,0x6f); //o
//  writeData(19,0x70); //p
//  writeData(20,0x54); //T
//  writeData(21,0x68); //h
//  writeData(22,0x69); //i
//  writeData(23,0x73); //s
//  writeData(24,0x4b); //K
//  writeData(25,0x65); //e
//  writeData(26,0x72); //r
//  writeData(27,0x6e); //n
//  writeData(28,0x65); //e
//  writeData(29,0x6c); //l
//  writeData(30,0x21); //!
//  writeData(31,0x00);
//  Serial.println("Complete");

  
  //read data back
  Serial.println("Reading data.");
  for (int i=0; i<100; i++)
  {
    //Serial.print(i);
    //Serial.print(" : ");
    d=readData(i);
    Serial.print(char(d));
  }
  Serial.println("Complete");
 
}
 
// writes a byte of data in memory location eaddress
void writeData(unsigned int eaddress, byte data) 
{
  Wire.beginTransmission(eeprom_address);
  // set the pointer position
  Wire.write((int)(eaddress >> 8));
  Wire.write((int)(eaddress & 0xFF));
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}
 
// reads a byte of data from memory location eaddress
byte readData(unsigned int eaddress) 
{
  byte result;
  Wire.beginTransmission(eeprom_address);
  // set the pointer position
  Wire.write((int)(eaddress >> 8));
  Wire.write((int)(eaddress & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(eeprom_address,1); // get the byte of data
  result = Wire.read();
  return result;
}
 
void loop()
{
}
