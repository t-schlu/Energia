//pin assignments
const int buttonPin1 = PUSH1;
const int buttonPin2 = PUSH2;

//initialize
int b1State = HIGH;
int b2State = HIGH;
int b2Past = HIGH;
int printVal = 0;

void setup() {
  
  //serial
  Serial.begin(9600);
  
  //input pins
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  b2State = digitalRead(buttonPin2); //check button 2
  
  //if button2 is pressed, record button1 value.
  if (b2State == LOW) {
    if (b2State != b2Past) {
      b1State = digitalRead(buttonPin1);
      if (b1State == HIGH)
        printVal = 0;
      else
        printVal = 1;
      Serial.println(printVal);
    }
  }
  b2Past = b2State; // only 1 record per press
  delay(100);  
}
