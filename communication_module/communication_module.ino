const int pulsePin = 2; // Input signal connected to Pin 8 of Arduino

int pulseHigh; // Integer variable to capture High time of the incoming pulse
int pulseLow; // Integer variable to capture Low time of the incoming pulse
float pulseTotal; // Float variable to capture Total time of the incoming pulse
float frequency; // Calculated Frequency

void setup()
{
    Serial.begin(115200); // Initialize the serial
    pinMode(pulsePin,INPUT);
    delay(5000);
}
void loop()
{
    pulseHigh = pulseIn(pulsePin,HIGH);
    pulseLow = pulseIn(pulsePin,LOW);
    
    pulseTotal = pulseHigh + pulseLow; // Time period of the pulse in microseconds
    frequency=1000000/pulseTotal; // Frequency in Hertz (Hz)

    Serial.print(frequency);
    Serial.print(" Hz");
    if (frequency > 90 && frequency < 110) {
      Serial.println(" | OK");
    }
    else {
      Serial.println(" | FAULT");
    }
    
    delay(500);
}
