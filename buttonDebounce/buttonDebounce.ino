const int ledPin = GREEN_LED;
const int buttonPin = PUSH1;



int buttonPast = LOW;
long timePast = 0;
long debounceDelay = 50;
int buttonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);

}

void loop() {
  int reading = digitalRead(buttonPin);
//  digitalWrite(RED_LED, reading);
  if (reading != buttonPast)
    timePast = millis();
  if ((millis() - timePast) > debounceDelay)
    buttonState = reading;
  digitalWrite(ledPin, buttonState);
  buttonPast = reading;
}
