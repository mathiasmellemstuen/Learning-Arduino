const int A = 10; 
const int B = 9; 
const int C = 7; 
const int D = 13; 
const int E = 12; 
const int F = 11;
const int G = 8; 

const int button_1 = 2; 
const int button_2 = 3;

const int bounceTime = 50; 
int lastTime = 0; 

/*
 * A   D
 * B G E
 * C   F
 */
 
void resetAll() {
  digitalWrite(A, LOW); 
  digitalWrite(B, LOW); 
  digitalWrite(C, LOW); 
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW); 
  digitalWrite(F, LOW); 
  digitalWrite(G, LOW); 
}

void setDice(int number) {

  switch(number) {
    case 1: 
      resetAll(); 
      digitalWrite(G, HIGH); 
    break; 
    case 2: 
      resetAll(); 
      digitalWrite(A, HIGH); 
      digitalWrite(F, HIGH); 
    break; 
    case 3: 
      resetAll(); 
      digitalWrite(A, HIGH); 
      digitalWrite(G, HIGH); 
      digitalWrite(F, HIGH);
    break; 
    case 4:
      resetAll(); 
      digitalWrite(A, HIGH); 
      digitalWrite(C, HIGH); 
      digitalWrite(D, HIGH); 
      digitalWrite(F, HIGH); 
    break; 
    case 5: 
      resetAll(); 
      digitalWrite(A, HIGH); 
      digitalWrite(C, HIGH); 
      digitalWrite(D, HIGH); 
      digitalWrite(F, HIGH); 
      digitalWrite(G, HIGH); 
    break; 
    case 6: 
      resetAll(); 
      digitalWrite(A, HIGH); 
      digitalWrite(B, HIGH); 
      digitalWrite(C, HIGH); 
      digitalWrite(D, HIGH); 
      digitalWrite(E, HIGH); 
      digitalWrite(F, HIGH); 
    break; 
  }
}

void randomDice() {

  if(lastTime > (millis() + bounceTime))
    return;
    

  lastTime = millis();
  
  
  int num = random(1, 7); 
  setDice(num); 
  
  Serial.print("Current dice: "); 
  Serial.println(num); 
}

void setup() {
  Serial.begin(9600); 
  
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT); 
  pinMode(C, OUTPUT); 
  pinMode(D, OUTPUT); 
  pinMode(E, OUTPUT); 
  pinMode(F, OUTPUT); 
  pinMode(G, OUTPUT); 
  pinMode(button_1, INPUT); 
  pinMode(button_2, INPUT);

  attachInterrupt(digitalPinToInterrupt(button_1), resetAll, RISING);
  attachInterrupt(digitalPinToInterrupt(button_2), randomDice, RISING); 
}



void loop() {}
