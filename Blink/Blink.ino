//pin assginments
const int ledPin1 = GREEN_LED;
const int ledPin2 = RED_LED;

//initialize variables
int ledState = LOW;
int ledSelect = ledPin1;
long previousMillis = 0;
long interval = 1000;
unsigned long currentMillis;


void setup() {
  
  //LED pins
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
}

void loop() { 
  
  //check time
  unsigned long currentMillis = millis();
  
  //check time since last blink
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    
    //change state
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledSelect, ledState);    
    if (ledState == LOW) {
      //change LED selection
      if (ledSelect == ledPin1)
        ledSelect = ledPin2;
      else
        ledSelect = ledPin1;  
    }
  }
}
