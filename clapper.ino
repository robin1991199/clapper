int SoundSensor = 2; // LM393 Sound Sensor Digital Pin D0 connected to pin 2
int LED = 3;         // LED connected to pin 3
boolean LEDStatus = false;
unsigned long lastClapTime = 0;
unsigned long clapInterval = 200; // Adjust as needed, this is the maximum time between two claps to be considered a double clap

void setup() {
  pinMode(SoundSensor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int SensorData = digitalRead(SoundSensor);
  Serial.println(SensorData); 

  if (SensorData == HIGH && (millis() - lastClapTime) > clapInterval) {
   
    lastClapTime = millis(); 

    // Check if this is the first clap of a potential double clap
    if (LEDStatus == false) {
      LEDStatus = true;
      digitalWrite(LED, HIGH);
    } else { // If it's the second clap
      // Reset LED status and turn off LED
      LEDStatus = false;
      digitalWrite(LED, LOW);
    }
  }
}
