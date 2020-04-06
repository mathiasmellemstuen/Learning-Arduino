#include <Servo.h>

Servo servo; 

const int servoPin = 9; 
const int potentiometerPin = A0; 
int potentiometerValue; 
int angle; 

int skaler(int potVal, int skalaLav, int skalaHoy, int vinkelLav, int vinkelHoy) {
  return (potVal - skalaLav) * (vinkelHoy - vinkelLav) / (skalaHoy - skalaLav) + vinkelLav; 
}

void setup() {
  servo.attach(servoPin); 

  Serial.begin(9600); 
}


void loop() {
  potentiometerValue = analogRead(potentiometerPin); 
  angle = skaler(potentiometerValue, 0, 1023, 0, 179);
  Serial.print(", angle: "); 
  Serial.print(angle); 
  servo.write(angle); 
  delay(15); 
}
