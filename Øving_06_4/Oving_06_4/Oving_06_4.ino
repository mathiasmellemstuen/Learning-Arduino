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

int melodi1[22]= {C1,D,E,F,G,G,A,A,A,A,G,F,F,F,F,E,E,D,D,D,D,C1};
int varighet1[22] = {1,1,1,1,2,2,1,1,1,1,4,1,1,1,1,2,2,1,1,1,1,4};

void setup() {
  Serial.begin(9600); 
}
void playTone(int _tone, int duration) {
  Serial.print("Playing tone: "); 
  Serial.println(_tone);
  
  tone(speakerPin, _tone, duration);
}
void playMelody(int *p_melody, int melodyLength, int *p_duration, int durationLength, int songSpeed) {
  
    for(int i = 0; i < melodyLength; i++) {

      int t = *(p_melody + i); 
      int d = *(p_duration + i); 

      playTone(t, d * songSpeed); 
      delay(d * songSpeed + 10); 
    }
}
void loop() {
  playMelody(melodi1,ARRAY_SIZE(melodi1),varighet1, ARRAY_SIZE(varighet1), 500); 
}
