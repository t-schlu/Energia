#include <CompileGaitData.h>
#include <math.h>

// Simulates knee torque with a virtual spring and damper

float angle1 = 0;
float angle2 = 0;
float sTorque, dTorque, deriv, torque;
float k1 = 3.78;
float k2 = 0.073;
float b = pow(25, -3);
float theta_e = 12*3.14159/180;
float deltaT = 1.4/1000;
float deltaTh = 0;

const int buttonPin = PUSH1;
const int ledPin =  GREEN_LED;
int buttonState = 0;
int mode = 1;

float angle1x;

CompileGaitData data;

// the setup routine runs once when you press reset:
void setup() {
  // Initialize LED output
  pinMode(ledPin, OUTPUT);
  // Initialize pushbotton pin as input
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
   for (int i = 0; i < 1001; i++)
   {
      angle2 = angle1;
      angle1 = data.getGaitData(i)*3.14159/180;
      if (theta_e > angle1)
      {
        deltaTh = theta_e - angle1;
      }
      else
      {
        deltaTh = angle1 - theta_e;
      }
      sTorque = k1*deltaTh + k2*pow(deltaTh, 3);
      deriv = (angle1 - angle2)/deltaT;
      dTorque = b*deriv;
      Serial.print("Percent: ");
      Serial.print(100*i/1001);
      Serial.print("   Knee Angle: ");
      Serial.print(data.getGaitData(i));
      Serial.print("   Spring Torque: ");
      Serial.print(sTorque);
      Serial.print("   Damper Torque: ");
      Serial.print(dTorque, 5);
      Serial.print("   Total Torque: ");
      Serial.print(sTorque + dTorque, 5);
      Serial.println();

      if (i == 380)
      {
       Serial.print("\n\n\n");
        Serial.println("MODE SWITCH: 1 TO 2");
        Serial.print("\n\n\n");
        k1 = 0;
        k2 = pow(9, -6);
        b = pow(30, -3);
        theta_e = 37*3.14159/180;
      }
      else if (i == 600)
      {
        Serial.print("\n\n\n");
        Serial.println("MODE SWTICH: 2 to 3");
        Serial.print("\n\n\n");
        k1 = 0;
        k2 = pow(9, -3);
        b = pow(16, -3);
        theta_e = 52*3.14159/180;
      }
      else if (i == 730)
      {
        Serial.print("\n\n\n");
        Serial.println("MODE SWTICH: 3 to 4");
        Serial.print("\n\n\n");
        k1 = pow(93, -3);
        k2 = pow(2, -6);
        b = pow(13, -3);
        theta_e = 44*3.14159/180;
      }
      else if (i == 1000)
      {
        Serial.print("\n\n\n");
        Serial.println("MODE SWTICH: 4 to 1");
        Serial.print("\n\n\n");
        k1 = 3.78;
        k2 = pow(73, -3);
        b = pow(25, -3);
        theta_e = 12*3.14159/180;
      }
      
      delay(1);
   } 
   Serial.print("\n\n\n\n\n\n\n\n\n");
}


