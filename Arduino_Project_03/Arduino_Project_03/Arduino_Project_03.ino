const int sensorPin = A0; 
const int delayMs = 500; 
const float baselineTemp = 20.0; 

void setup() {

  for(int i = 3; i < 5; i++) {
    pinMode(i, OUTPUT); 
    digitalWrite(i,LOW); 
  }
  
  Serial.begin(9600); 
  Serial.print("Starting."); 
}

float getSensorValueCelcius() {

  int sensorRawValue = analogRe|ad(sensorPin); 
  float voltage = (sensorRawValue / 1024.0) * 5.0; 
  float celcius = (voltage - .5) * 100; 
  return celcius; 
}

void setOutput(int led1, int led2, int led3) {
  digitalWrite(3,led1); 
  digitalWrite(4,led2); 
  digitalWrite(5,led3); 
}
void loop() {

  float temp = getSensorValueCelcius(); 

  if(temp < baselineTemp) {
    setOutput(LOW,LOW,LOW);  
  }
  else if(temp >= baselineTemp && temp < baselineTemp+4) {
    setOutput(HIGH,LOW,LOW); 
  }
  else if(temp >= baselineTemp+4 && temp < baselineTemp+6) {
    setOutput(HIGH,HIGH,LOW);
  }
  else if(temp >= baselineTemp+6) {
    setOutput(HIGH,HIGH,HIGH);
  }
  Serial.print(temp); 
  Serial.print("C "); 
  delay(delayMs); 
}
