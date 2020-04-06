#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); 

const int switchPin = 6; 
int switchState = 0;

int currentPosition = -1; 

int nextPosition() {
  if(currentPosition == 31) {
    currentPosition = 0;
    return currentPosition; 
  } else {
    currentPosition++; 
  }
  return currentPosition > 15 ? (currentPosition - 16) : currentPosition; 
}
int nextLevel() {
  return currentPosition >= 16 ? 1 : 0; 
}

void setup() {
  
  lcd.begin(16,2);
}


void loop() {
  switchState = digitalRead(switchPin);
  int pos = nextPosition(); 
  int level = nextLevel(); 

  if(switchState == HIGH) { // Bruker switchState som en reset. 
    currentPosition = 0; 
    pos = 0;
    level = 0; 
  }
  
  lcd.clear(); 
  lcd.setCursor(pos,level); 
  lcd.print("#"); 
  delay(50); 
  
}
