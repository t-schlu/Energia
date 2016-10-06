void setup() {
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  int reading = analogRead(A0);
  int brightness = 255.0 * reading / 1023.0;
  analogWrite(GREEN_LED, brightness);
  delay(100);
}
