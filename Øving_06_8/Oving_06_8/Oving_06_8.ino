const int sensor1Pin = A0; 
const float limit = 0.6; 
const int sensorSampleTime = 2000; 
int getSensorValue(int sensorNumber) {
  switch(sensorNumber) {
    case 1: 
      return analogRead(sensor1Pin);
    break; 
    case 2: 
      return simulateSensorValue();
    break; 
    case 3: 
      return simulateSensorValue();
    break; 
  }
}

int simulateSensorValue() {
  return random(144,146); //Representerer ca 20 C. 
}
int simulateFaultySensorValue() {
  return random(1,1023); 
}
void clearConsole() {
Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void setup() {
  Serial.begin(9600); 
}

float sensorValueToTemperature(int sensorValue) {
  float voltage = ((float)sensorValue / 1024.0) * 5.0; 
  return (voltage - 0.5) * 100.0; 
}
void loop() {


  float sensorValue1 = sensorValueToTemperature(getSensorValue(1)); 
  float sensorValue2 = sensorValueToTemperature(getSensorValue(2));
  float sensorValue3 = sensorValueToTemperature(getSensorValue(3));

  boolean sensorsWorking = sensorValue1 <= sensorValue2 + limit && sensorValue1 >= sensorValue2 - limit && sensorValue1 <= sensorValue3 + limit && sensorValue1 >= sensorValue3 - limit;
  if(sensorsWorking) {
    float average = (sensorValue1 + sensorValue2 + sensorValue3) / 3.0; 

    clearConsole(); 
    Serial.println("Sensorene er OK."); 
    Serial.print("Gjennomsnittelig verdi: "); 
    Serial.print(average); 
    Serial.println("C."); 
    
  } else {
    clearConsole();
    Serial.println("En eller flere sensorer er utenfor spesifikasjonen og må undersøkes."); 
    Serial.println("Verdier:");
    Serial.print("Sensor 1: "); 
    Serial.print(sensorValue1); 
    Serial.println("C."); 
    Serial.print("Sensor 2: "); 
    Serial.print(sensorValue2); 
    Serial.println("C."); 
    Serial.print("Sensor 3: "); 
    Serial.print(sensorValue3); 
    Serial.println("C."); 
  }
  delay(sensorSampleTime); 
}
