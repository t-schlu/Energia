const int sensorPin = A3;
const int calibLedPin = PN_1;
const int ledPin = PD_7;

int sensorValue = 0;
int sensorMax = 0;
int sensorMin = 4095;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(calibLedPin, OUTPUT);
  digitalWrite(calibLedPin, HIGH);
  
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax)
      sensorMax = sensorValue;
    if (sensorValue < sensorMin)
      sensorMin = sensorValue;
  }
  digitalWrite(calibLedPin, LOW);
  Serial.print("sensorMin = ");
  Serial.print(sensorMin);
  Serial.print("\tsensorMax = ");
  Serial.println(sensorMax);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  outputValue= map(sensorValue, sensorMin, sensorMax, 0, 255);
  analogWrite(ledPin, outputValue);
  
}
