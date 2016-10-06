//pin assignment
const int buttonPin = PUSH1;
const int ledPin = GREEN_LED;

//variables
int buttonPast = HIGH;
int counter = 0;
int buttonState = HIGH;

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {
  
  buttonState = digitalRead(buttonPin); //read state

  if (buttonState != buttonPast) {
    if (buttonState == LOW) {
      counter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    }
    else
      Serial.println("off");
  }

  //record buttonPast
  buttonPast = buttonState;

  if (counter % 4 == 0)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  delay(100);
}
