//pin assignments
const int led1 = GREEN_LED;
const int led2 = RED_LED;
const int push1 = PUSH1;
const int push2 = PUSH2;

//initialize variables
int pushPast1 = HIGH;
int pushPast2 = HIGH;
int pushState1 = HIGH;
int pushState2 = HIGH;
int ledState1 = LOW;
int ledState2 = LOW;

void setup() {

  //set up pin modes
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
    pinMode(push1, INPUT_PULLUP);
    pinMode(push2, INPUT_PULLUP);

  }

void loop() {

  //read push values
  pushState1 = digitalRead(push1);
  pushState2 = digitalRead(push2);

  //***PUSH1***
  if (pushState1 != pushPast1) {  //check for button switch

    //change LED state if button is low
    if (pushState1 == LOW) {
      if (ledState1 == LOW)
        ledState1 = HIGH;
      else
        ledState1 = LOW;
      digitalWrite(led1, ledState1);
    }
  }

  //***PUSH2*** (almost identical to PUSH1
  if (pushState2 != pushPast2) {
    if (pushState2 == LOW) {
      if (ledState2 == LOW)
        ledState2 = HIGH;
      else
        ledState2 = LOW;
      digitalWrite(led2, ledState2);
    }
  }

  //record old button push values
  pushPast1 = pushState1;
  pushPast2 = pushState2;
  
}
