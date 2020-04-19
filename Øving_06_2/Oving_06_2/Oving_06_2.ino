const int redPin = 9; 
const int yellowPin = 10; 
const int greenPin = 11; 
const int buttonPin = 2; 
const int delayTime = 10; 
const unsigned long bounceDelay = 250; // Milli

int intensivity = 1; 

volatile unsigned long lastButtonTime = 0; 
volatile int selectedLED = 1;

void setup() {
  pinMode(redPin, OUTPUT); 
  pinMode(yellowPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(buttonPin, INPUT); 
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeSelectedLED, RISING); 
}
void writeToSelectedLED() {
  
    switch(selectedLED) {
    case 1: 
      analogWrite(redPin, intensivity); 
      analogWrite(yellowPin, 0); 
      analogWrite(greenPin, 0);
    break; 
    case 2:
      analogWrite(redPin, 0); 
      analogWrite(yellowPin, intensivity); 
      analogWrite(greenPin, 0);
    break; 
    case 3:
      analogWrite(redPin, 0); 
      analogWrite(yellowPin, 0); 
      analogWrite(greenPin, intensivity);
    break; 
  }
}
void changeSelectedLED() {
  
  if(millis() < (lastButtonTime + bounceDelay))
    return; 

  lastButtonTime = millis(); 
  
  selectedLED = selectedLED >= 3 ? 1 : (selectedLED + 1);
}
void loop() {
  for(int i = 0; i < 255; i++) {
    intensivity = i; 
    writeToSelectedLED(); 
    delay(delayTime); 
  }

  for(int i = 255; i > 0; i--) {
    intensivity = i; 
    writeToSelectedLED(); 
    delay(delayTime); 
  }
}
