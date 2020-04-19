#include <TimerOne.h>

#define ARRAY_SIZE(x) ((sizeof(x))/(sizeof(x[0])))

#define C1 260
#define D 292 
#define E 328
#define F 348
#define G 392
#define A 440
#define H 492
#define C2 520

const int speakerPin = 12; 
const unsigned long timerMicroseconds = 400000;
const int timerMilliseconds = 400; 

const int scale[] = {C1, D, E, F, G, A, H, C2}; 
const char scaleNoteName[] = {'C','D','E','F','G','A','H','C'}; 

int currentScaleIndex = -1; 

int nextScaleIndex() {
  currentScaleIndex = currentScaleIndex >= ARRAY_SIZE(scale) ? 0 : (currentScaleIndex + 1);
  return currentScaleIndex; 
}

void timer() {
  tone(speakerPin, scale[nextScaleIndex()],timerMilliseconds);
}

void setup() {
  Serial.begin(9600); 
  Timer1.initialize(timerMicroseconds);
  Timer1.attachInterrupt(timer);  

}

void loop() {
  Serial.print("Current tone: "); 
  Serial.println(scaleNoteName[currentScaleIndex]); 
  delay(timerMilliseconds);  
}
