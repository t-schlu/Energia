const int sensorPin = PE_0;
const int ledPin = PN_1;

int sensorValue = 0;
int hightime = 0;
int lowtime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  hightime = map(sensorValue,0,4095,500,2000);
  delay(hightime);
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, LOW);
  lowtime = map(sensorValue,0,4095,500,2000);
  delay(lowtime); 
  
}
