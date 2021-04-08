int i1 = 4;
int i2 = 5;
int i3 = 6;
int i4 = 7;
int i5 = 8;
int i6 = 9;

int o1 = A1;
int o2 = A0;
int o3 = 13;
int o4 = 12;
int o5 = 11;
int o6 = 10;

bool alltrue = true;
String outputString = "";

char *myStrings[] = {"100011","100011","100011","100011","100111","100111","100111","100111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111","100011","110011","101011","111011","100111","110111","101111","111111"};
void setup()
{
  Serial.begin(9600); // Initialize the serial
  pinMode(i1, OUTPUT);
  pinMode(i2, OUTPUT);
  pinMode(i3, OUTPUT);
  pinMode(i4, OUTPUT);
  pinMode(i5, OUTPUT);
  pinMode(i6, OUTPUT);

  pinMode(o1, INPUT_PULLUP);
  pinMode(o2, INPUT_PULLUP);
  pinMode(o3, INPUT_PULLUP);
  pinMode(o4, INPUT_PULLUP);
  pinMode(o5, INPUT_PULLUP);

  //special case of output6, which is acting as vcc for and/or gates
  pinMode(o6, OUTPUT);
  digitalWrite(o6, HIGH);
}


void writeINPUTS(char* x ){
  digitalWrite(i1,LOW);
  digitalWrite(i2,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i4,LOW);
  digitalWrite(i5,LOW);
  digitalWrite(i6,LOW);
  delay(50);
  if (x[0] == '0'){digitalWrite(i1,LOW);} else{digitalWrite(i1,HIGH);}
  if (x[1] == '0'){digitalWrite(i2,LOW);} else{digitalWrite(i2,HIGH);}
  if (x[2] == '0'){digitalWrite(i3,LOW);} else{digitalWrite(i3,HIGH);}
  if (x[3] == '0'){digitalWrite(i4,LOW);} else{digitalWrite(i4,HIGH);}
  if (x[4] == '0'){digitalWrite(i5,LOW);} else{digitalWrite(i5,HIGH);}
  if (x[5] == '0'){digitalWrite(i6,LOW);} else{digitalWrite(i6,HIGH);}
  
  
}

void checkOUTS(int i){
  outputString = "";
  outputString += digitalRead(o1);
  outputString += digitalRead(o2);
  outputString += digitalRead(o3);
  outputString += digitalRead(o4);
  outputString += digitalRead(o5);
  outputString += "1"; //dont need to read it, because its always high for vcc
  //Serial.print(outputString);
  //Serial.print(" : ");
  //Serial.print(myStrings[i]);
  if (outputString != myStrings[i]){
    alltrue = false;
    //Serial.println(" : false");
  }
  else{
    //Serial.println(" : true");
  }
  
  
}

void loop()
{
   alltrue = true;
   for (int i=0; i<64; i++) {
    byte someValue = i; //For this example, lets convert the number 20
    char binary[8] = {0}; //This is where the binary representation will be stored
    someValue += 64; //Adding 64 so that there will always be 8 digits in the string
    itoa(someValue,binary,2); //Conver someValue to a string using base 2 and save it in the array named binary
    char* string = binary + 1; //get rid of the most significant digit as you only want 6 bits
    writeINPUTS(string);
    delay(50);
    //if (i<10) Serial.print('0');
    //Serial.print(i);
    //Serial.print(": ");
    
    checkOUTS(i);
   }
   
   if (alltrue == true){
    Serial.print("%POWER_MODULE%OK%123456abcdf%\r");
   }
   else{
    Serial.print("%POWER_MODULE%FAULT%\r");
   }
}
