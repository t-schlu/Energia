//initialize variables
int brightnessG = 0;
int brightnessB = 125;
int brightnessR = 250;
int fadeAmountG = 5;
int fadeAmountB = 5;
int fadeAmountR = -5;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  //set brightness of each LED
  analogWrite(GREEN_LED, brightnessG);
  analogWrite(BLUE_LED, brightnessB);
  analogWrite(RED_LED, brightnessR);
  //change brightness levels for next loop
  brightnessG = brightnessG + fadeAmountG;
  brightnessB = brightnessB + fadeAmountB;
  brightnessR = brightnessR + fadeAmountR;
  //reverse fade value if at extremity
  if(brightnessG == 0 || brightnessG == 250) {
    fadeAmountG = -fadeAmountG;
  }
  if(brightnessB == 0 || brightnessB == 250) {
    fadeAmountB = -fadeAmountB;
  }
  if(brightnessR == 0 || brightnessR == 250) {
    fadeAmountR = -fadeAmountR;
  }
  delay(50);
}
