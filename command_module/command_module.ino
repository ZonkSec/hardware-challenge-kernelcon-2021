String input;
int fuel_module = A0;
int temp_module = A7;
int oxy_module = A1;
int comm_module = A2;
int power_module = A3;
bool everything_okay;

void setup() {
  pinMode(fuel_module, INPUT);
  pinMode(temp_module, INPUT);
  pinMode(oxy_module, INPUT);
  pinMode(comm_module, INPUT);
  pinMode(power_module, INPUT);
  Serial.begin(9600);
  clearscreen();
  print_welcome();
}

void loop() {
  Serial.print("LCM> ");
  while(!Serial.available() ){}
  input ="";
  input = Serial.readStringUntil('\r');
  Serial.print("LCM> ");
  Serial.println(input);
  if (input == "SR"){
    command_sr();
  }
  else if (input == "LOG"){
    command_log();
  }
  else if (input == "HELP"){
    print_welcome();
  }
  else if (input == "LAUNCH"){
    command_launch();
  }
  else {
    Serial.println("UNKOWN COMMAND");
  }

}
void clearscreen(){
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}
void print_welcome(){
  Serial.println(F(" _      _____  ___  ___  "));
  Serial.println(F("| |    /  __ \\ |  \\/  |  "));
  Serial.println(F("| |    | /  \\/ | .  . |  "));
  Serial.println(F("| |    | |     | |\\/| |  "));
  Serial.println(F("| |____| \\__/\\_| |  | |_ "));
  Serial.println(F("\\_____(_)____(_)_|  |_(_)"));
  Serial.println(F(""));
  Serial.println(F("Launch Control Module v1.3.37"));
  Serial.println(F(""));
  Serial.println(F("COMMANDS:"));
  Serial.println(F(""));
  Serial.println(F("SR     = module status report."));
  Serial.println(F("LOG    = returns last log log of modules"));
  Serial.println(F("LAUNCH = launches vessel if all modules are active"));
  Serial.println(F("HELP   = displays this menu"));
  Serial.println(F(""));
}

void command_log(){
    Serial.println("LOGS:");
    Serial.println("----------------------");
    Serial.println("1 COMMUNICATION");
    Serial.println("2 MEMORY");
    Serial.println("3 ENGINE HEAT");
    Serial.println("4 FUEL");
    Serial.println("5 POWER DISTRO");
    Serial.println("");
    Serial.print("SELECT MODULE: ");
    while(!Serial.available() ){}
    input ="";
    input = Serial.readStringUntil('\r');
    Serial.print("SELECT MODULE: ");
    Serial.println(input);
    if (input == "1"){
      Serial.println("COMMUNICATION LOG:");
      Serial.println("10/26/2556 0657 UTC: RADIOS ARE DOWN AGAIN. BASE OSCILLATION ERROR. IT NEEDS 10 HZ. I JUST HAD THE INTERN FIX IT TOO!");
    }
    else if (input == "2"){
      Serial.println("MEMORY LOG");
      Serial.println("10/26/2556 0657 UTC: MEMORY MODULE IS COMPLETELEY DESTROYED. WE'LL NEED TO RECOVER DATA  AND INPUT USING MANUAL MODE");
    }
    else if (input == "3"){
      Serial.println("ENGINE HEAT LOG");
      Serial.println("10/26/2556 0657 UTC: ENGINES CAN PRIME WITHOUT THE PROPER HEAT. SOMETHING MIGHT BE WRONG IN SENSING CIRCUIT");
    }
    else if (input == "4"){
      Serial.println("FUEL LOG");
      Serial.println("10/26/2556 0657 UTC: ONLY RECIEVEING 1/4 THE FUEL WE SHOULD BE...HMMMMM");
    }
    else if (input == "5"){
      Serial.println("POWER DISTRO LOG");
      Serial.println("10/26/2556 0657 UTC: THIS CIRCUIT WAS DAMAGED BEYOND REPAIR, SO WE RECREATED THE BOARD FROM THE ORIGINAL SCHEMATIC (WHICH IS ATTACHED TO MODULE) AND IT DOESNT WORK, MAYBE WE DID SOMETHING WRONG?");
    }
    else{
      Serial.println("UNKOWN LOG");
    }
}

void command_sr(){
    everything_okay = true;
      Serial.println(F("+---------------+------------+--------------+"));
      Serial.println(F("|    MODULE     | CONNECTED  | STATUS       |"));
      Serial.println(F("+---------------+------------+--------------+"));
    
    int oxy_module_status = pulseIn(oxy_module,HIGH);
    if (oxy_module_status == 0){
      Serial.println(F("| OXYGEN SUPPLY | NO         | -            |"));
      everything_okay = false;
    }
    else if (oxy_module_status > 0 && oxy_module_status < 3000){
      Serial.println(F("| OXYGEN SUPPLY | YES        | FAULT        |"));
      everything_okay = false;
    }
    else if (oxy_module_status > 3000){
      Serial.println(F("| OXYGEN SUPPLY | YES        | OK           |"));
    }

    int temp_module_status = pulseIn(temp_module,HIGH);
    if (temp_module_status == 0){
      Serial.println(F("| ENGINE TEMP   | NO         | -            |"));
      everything_okay = false;
    }
    else if (temp_module_status > 0 && oxy_module_status < 3000){
      Serial.println(F("| ENGINE TEMP   | YES        | FAULT        |"));
      everything_okay = false;
    }
    else if (temp_module_status > 3000){
      Serial.println(F("| ENGINE TEMP   | YES        | OK           |"));
    }
    
    int fuel_module_status = pulseIn(fuel_module,HIGH);
    if (fuel_module_status == 0){
      Serial.println(F("| FUEL          | NO         | -            |"));
      everything_okay = false;
    }
    else if (fuel_module_status > 0 && oxy_module_status < 3000){
      Serial.println(F("| FUEL          | YES        | FAULT        |"));
      everything_okay = false;
    }
    else if (fuel_module_status > 3000){
      Serial.println(F("| FUEL          | YES        | OK           |"));
    }

    int power_module_status = pulseIn(power_module,HIGH);
    if (power_module_status == 0){
      Serial.println(F("| POWER DISTRO  | NO         | -            |"));
      everything_okay = false;
    }
    else if (power_module_status > 0 && oxy_module_status < 3000){
      Serial.println(F("| POWER DISTRO  | YES        | FAULT        |"));
      everything_okay = false;
    }
    else if (power_module_status > 3000){
      Serial.println(F("| POWER DISTRO  | YES        | OK           |"));
    }

    int comm_module_status = pulseIn(comm_module,HIGH);
    if (comm_module_status == 0){
      Serial.println(F("| COMMUNICATION | NO         | -            |"));
      everything_okay = false;
    }
    else if (comm_module_status > 0 && oxy_module_status < 3000){
      Serial.println(F("| COMMUNICATION | YES        | FAULT        |"));
      everything_okay = false;
    }
    else if (comm_module_status > 3000){
      Serial.println(F("| COMMUNICATION | YES        | OK           |"));
    }
    
    Serial.println(F("| MEMORY        | -          | MANUAL MODE  |"));  
    Serial.println(F("+---------------+------------+--------------+"));
}
void command_launch(){
  if (everything_okay == true){
      for (int i = 10; i >= 0; i--) {
        clearscreen();
        Serial.print("...");
        Serial.println(i);
        delay(1000);
    }
    clearscreen();
    Serial.println("LIFT OFF!");
    delay(1000);
    clearscreen();
    win();
    delay(100000);
    
  }
  else{
    Serial.println("UNABLE TO LAUNCH. RUN STATUS REPORT TO PERFORM SYSTEM CHECK.");
  }

}

void win(){
    Serial.println(F("                         .-."));
    Serial.println(F("                        ( ("));
    Serial.println(F("                         `-'"));
    Serial.println(F(""));
    Serial.println(F(""));
    Serial.println(F("                    .      - HACK THE UNIVERSE!"));
    Serial.println(F("                   .'."));
    Serial.println(F("                   |o|"));
    Serial.println(F("                  .'o'."));
    Serial.println(F("                  |.-.|"));
    Serial.println(F("                  '   '"));
    Serial.println(F("                   ( )"));
    Serial.println(F("                    )"));
    Serial.println(F("                   ( )"));
    Serial.println(F("                    )"));
    Serial.println(F("                   ( )"));
    Serial.println(F("                    )"));
    Serial.println(F("                   ( )"));
    Serial.println(F(""));
    Serial.println(F(""));
    Serial.println(F(""));
    //Serial.println(F("       THANKS FOR PLAYING JOE! -ZONKSEC"));
}
