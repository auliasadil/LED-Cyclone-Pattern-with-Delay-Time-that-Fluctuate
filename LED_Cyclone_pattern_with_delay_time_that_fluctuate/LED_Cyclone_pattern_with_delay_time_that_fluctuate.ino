// Written by Muhammad Aulia Adil 

// Connect 9 LEDs with this pins. You can actually light up more LEDs, just add up the pin and LED
const int LED[9] = {13, 12, 11, 10, 9, 8, 7, 5, 3};

// This will set your LEDs pin mode into OUTPUT
void setup(){
  for(int i = 0; i < 9; i++){
    pinMode(LED[i], OUTPUT);
}
}


void loop(){
  int i = 0;
  int period = 1000;
  phase1: //phase1 is when the delay time is decreasing and the LED pin 13 is going to LED pin 3
  if(i == 8){
    goto phase2;
  }
  if(period == 100){
    goto phase3;
  }
  digitalWrite(LED[i], HIGH);
  delay(period);
  digitalWrite(LED[i], LOW);
  period = period - 100;
  i = i + 1;
  goto phase1;

  phase2: //phase2 is when the delay time is decreasing and the LED pin 3 is going to LED pin 13
  if(i == 0){
    goto phase1;
  }
  if(period == 100){
    goto phase4;
  }
  digitalWrite(LED[i], HIGH);
  delay(period);
  digitalWrite(LED[i], LOW);
  period = period - 100;
  i = i - 1;
  goto phase2;

  phase3: //phase3 is when the delay time is increasing and the LED pin 3 is going to LED pin 13
  if(i == 8){
    goto phase4;
  }
  if(period == 1000){
    goto phase1;
  }
  digitalWrite(LED[i], HIGH);
  delay(period);
  digitalWrite(LED[i], LOW);
  period = period + 100;
  i = i + 1;
  goto phase3;

  phase4: //phase4 is when the delay time is increasing and the LED pin 13 is going to LED pin 3
  if(i == 0){
    goto phase3;
  }
  if(period == 1000){
    goto phase2;
  }
  digitalWrite(LED[i], HIGH);
  delay(period);
  digitalWrite(LED[i], LOW);
  period = period + 100;
  i = i - 1;
  goto phase4;
}

