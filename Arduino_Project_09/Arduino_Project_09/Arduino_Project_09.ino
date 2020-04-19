const int switchPin = 2; 
const int motorPin = 9; 

void setup() {
  pinMode(motorPin, OUTPUT); 
  pinMode(switchPin, INPUT); 
}

void loop() {
  digitalWrite(motorPin, digitalRead(switchPin));
}
