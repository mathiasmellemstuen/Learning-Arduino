const int speakerPin = 8;
const int inputPin = A0; 

int notes[] = {262, 294, 330, 349, 440};

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int keyValue = analogRead(inputPin);


  Serial.print(keyValue); 
  Serial.print(" , ");
  
  if (keyValue == 1023) {
    tone(speakerPin, notes[0]);
  } else if (keyValue >= 990 && keyValue <= 1010) {
    tone(speakerPin, notes[1]);
  } else if (keyValue >= 505 && keyValue <= 515) {
    tone(speakerPin, notes[2]);
  } else if (keyValue >= 5 && keyValue <= 10) {
    tone(speakerPin, notes[3]);
  } else if(keyValue >= 921 && keyValue <= 941) {
    tone(speakerPin, notes[4]); 
  } else {
    noTone(speakerPin);
  }
}
