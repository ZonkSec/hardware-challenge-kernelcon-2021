String input;

void setup() {
  // put your setup code here, to run once:
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
  Serial.println(F("| |    /  __ \ |  \/  |  "));
  Serial.println(F("| |    | /  \/ | .  . |  "));
  Serial.println(F("| |    | |     | |\/| |  "));
  Serial.println(F("| |____| \__/\_| |  | |_ "));
  Serial.println(F("\_____(_)____(_)_|  |_(_)"));
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
    Serial.println("+---------------+------------+--------------+");
    Serial.println("|    MODULE     | CONNECTED  | STATUS       |");
    Serial.println("+---------------+------------+--------------+");
    Serial.println("| OXYGEN SUPPLY | YES        | OK           |");
    Serial.println("| MEMORY        | -          | MANUAL MODE  |");
    Serial.println("| ENGINE HEAT   | NO         | -            |");
    Serial.println("| FUEL          | NO         | -            |");
    Serial.println("| POWER DISTRO  | NO         | -            |");
    Serial.println("| COMMUNICATION | NO         | -            |");
    Serial.println("+---------------+------------+--------------+");
}
void command_launch(){
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
