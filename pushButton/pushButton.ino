int buttonState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(73, INPUT_PULLUP);

}

void loop() {
  buttonState = digitalRead(73);
  Serial.println(buttonState);
  delay(100);
  
}
