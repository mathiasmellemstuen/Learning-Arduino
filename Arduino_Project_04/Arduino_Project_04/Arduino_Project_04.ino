const int greenLED = 9; 
const int redLED = 11; 
const int blueLED = 10; 

const int redSensor = A0; 
const int greenSensor = A1; 
const int blueSensor = A2;

int redValue = 0; 
int blueValue = 0; 
int greenValue = 0; 

void lesAnalog() {
  redValue = analogRead(redSensor); 
  delay(5); 
  blueValue = analogRead(blueValue); 
  delay(5); 
  greenValue = analogRead(greenValue);
}

//skrivAnalog: 
void setLEDColor(int red, int blue, int green) {
  analogWrite(redLED, red); 
  analogWrite(blueLED, blue); 
  analogWrite(greenLED, green); 
}

void setup() {
  Serial.begin(9600);
  
  pinMode(greenLED, OUTPUT); 
  pinMode(blueLED, OUTPUT); 
  pinMode(redLED, OUTPUT); 
}


void loop() {
  lesAnalog(); 
  delay(50); 
  Serial.print(" Grønn: "); 
  Serial.print(greenValue); 
  Serial.print(" Rød: "); 
  Serial.print(redValue); 
  Serial.print(" Blue: "); 
  Serial.print(blueValue); 
  setLEDColor(redValue, blueValue, greenValue); 
}
