#include <CompileGaitData.h>
#include <Servo.h>

Servo myservo;
CompileGaitData data;

const int potPin = PE_0;
const int motorPin = PE_1;

int potReading = 0;
float pos = 0;
int arrayVal = 0;

void setup() {
  
  myservo.attach(motorPin);
  Serial.begin(9600);
  
}

void loop() {
  
  potReading = analogRead(potPin);
  arrayVal = map(potReading, 0, 4095, 0, 1000);
  pos = data.getGaitData(arrayVal);
  myservo.write(pos);
  Serial.print(arrayVal);
  Serial.print("\t");
  Serial.println(pos);
  delay(100);
  
}
