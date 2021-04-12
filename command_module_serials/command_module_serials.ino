//String module_name = "OXYGEN_MODULE";
//String valid_signature = "33fdd8f3ac0";
//String module_name = "FUEL_MODULE";
//String valid_signature = "3b429d7e669";
String module_name = "COMMS_MODULE";
String valid_signature = "a49723307bb";
//String module_name = "POWER_MODULE";
//String valid_signature = "17f27f6b7b7";
//String module_name = "TEMP_MODULE";
//String valid_signature = "5ce5a69ac3f";

String input;
int pin_lcm = 10;
unsigned long timeout = 10000;
unsigned long timeoutStart;


void setup() {
  pinMode(pin_lcm, OUTPUT);
  Serial.begin(9600);
  Serial.println(module_name+ "_INTF: BOOT COMPLETE");
  analogWrite(pin_lcm,0);
}


//message format
//%module%state%signature%
void loop() {
  
  timeoutStart = millis(); //this gets set only after a serial message is decoded and loop starts again.
  while(!Serial.available() ){ //sits in the this loop if there is no serial data. after 10 seconds, it will timeout and set pin10 to 0, telling LCM nothing is connected.
    if (millis() - timeoutStart >= timeout){
      analogWrite(pin_lcm,0);
      timeoutStart = millis(); //reset the start time, so that this only runs every 10sec
      Serial.println(module_name+ "_INTF: TIMEOUT. NOTHING CONNECTED");
    }
  }
  
  analogWrite(pin_lcm,127);
  input ="";
  input = Serial.readStringUntil('\r');

  //parse the input. looking for %module%state%sig% | %OXYGEN_MODULE%OK%123456abcdf%
  int delimiter, delimiter_1, delimiter_2,delimiter_3;
  delimiter = input.indexOf("%");
  delimiter_1 = input.indexOf("%", delimiter + 1);
  delimiter_2 = input.indexOf("%", delimiter_1 +1);
  delimiter_3 = input.indexOf("%", delimiter_2 +1);
  String module = input.substring(delimiter + 1, delimiter_1);
  String state = input.substring(delimiter_1 + 1, delimiter_2);
  String signature = input.substring(delimiter_2 + 1, delimiter_3);


  if (!(module == module_name)){
    Serial.println(module_name+ "_INTF: UNRECOGNIZED INPUT");
  }
  else{
    if (state == "OK" && signature == valid_signature){
      Serial.println(module_name+ "_INTF: OK SET");
      analogWrite(pin_lcm,254);
    }
    else if (state == "OK" && !(signature == valid_signature)){
      Serial.println(module_name+ "_INTF: FAULT - INCORRECT SIGNATURE");
    }
    else if (state == "FAULT"){
      Serial.println(module_name+ "_INTF: FAULT SET");
    }
    else{
      Serial.println(module_name+ "_INTF: FAULT - UNRECOGNIZED STATE");
    }
  }
}
