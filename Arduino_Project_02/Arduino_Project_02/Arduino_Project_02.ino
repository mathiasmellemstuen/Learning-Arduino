
int state = 0; 

void setup() {
  
  pinMode(2, INPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
}

void loop() {
  state = digitalRead(2);

  if(state == LOW) {
    
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW); 
      digitalWrite(5, LOW); 
    
  } else if(state == HIGH) {

    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH); 

    delay(250); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, LOW); 
    delay(250); 
  }
}
