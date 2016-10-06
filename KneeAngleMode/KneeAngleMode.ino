

// pin assignments
const int ledPin1 = PN_1;
const int ledPin2 = PN_0;
const int ledPin3 = PF_4;
const int ledPin4 = PF_0;
const int pushPin1 = PJ_0;

//variable initialize
int mode = 1;
int pushReading = HIGH;
int pushReadingPast = HIGH;

void setup() {

  //allow serial comm.
  Serial.begin(9600);

  //set pin modes
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(pushPin1, INPUT_PULLUP);

}

void loop() {

  //if push button is pressed, move to next mode
  pushReading = digitalRead(pushPin1);
  if (pushReading != pushReadingPast) {
    if (pushReading == LOW){
      mode = mode + 1;
      if (mode == 5)
        mode = 1;
    }
    pushReadingPast = pushReading;
  }

  switch (mode) {
    case 1:
      DERP
      break;
  }

  //display LED based on what mode we are in
  //led: pin 1
  if (mode == 1)
    digitalWrite(ledPin1, HIGH);
  else
    digitalWrite(ledPin1, LOW);

    //led: pin 2
  if (mode == 2)
    digitalWrite(ledPin2, HIGH);
  else
    digitalWrite(ledPin2, LOW);

    //led: pin 3
  if (mode == 3)
    digitalWrite(ledPin3, HIGH);
  else
    digitalWrite(ledPin3, LOW);

    //led: pin 4
  if (mode == 4)
    digitalWrite(ledPin4, HIGH);
  else
    digitalWrite(ledPin4, LOW);

  delay(100);

}
