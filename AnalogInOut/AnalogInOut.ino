const int analogInPin1 = A3;
const int analogOutPin1 = PD_7;
const int analogInPin2 = A2;
const int analogOutPin2 = PD_3;

int sensorValue1 = 0;
int outputValue1 = 0;
int sensorValue2 = 0;
int outputValue2 = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  outputValue1 = map(sensorValue1, 0, 4095, 0, 255);
  outputValue2 = map(sensorValue2, 0, 4095, 0, 255);
  analogWrite(analogOutPin1, outputValue1);
  analogWrite(analogOutPin2, outputValue2);

  Serial.print("sensor1 = ");
  Serial.print(sensorValue1);
  Serial.print("\t output1 = ");
  Serial.print(outputValue1);
  Serial.print("\t sensor2 = ");
  Serial.print(sensorValue2);
  Serial.print("\t output2 = ");
  Serial.println(outputValue2);

  delay(100);
  
  
}
