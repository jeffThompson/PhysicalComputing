
/*
  MAPPING SENSOR VALUES
  Jeff Thompson | 2019 | jeffreythompson.org

  Our analog pins give us values between 0-1023, but often
  we might need those values in another range, say 0-255
  to control the fade of an LED.
  
*/

int sensorPin = A0;   // potentiometer input
int ledPin =    9;    // attached to a PWM-capable pin


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  
  // read the potentiometer value
  int value = analogRead(sensorPin);

  // if we want to convert a input from one range of 
  // numbers (0-1023) to another, we can use the map()
  // and constrain() functions

  // first, convert the value from 0-1023 to the range 0-255...
  
  // map() arguments are:
  //          input, in low, in high, out low, out high
  value = map(value, 0,      1023,    0,       255);

  // in some cases, we need to be sure our output doesn't go
  // past a certain range (like when fading an LED) – the 
  // constrain() function does just that

  // constrain() arguments are:
  //                input, low, high
  value = constrain(value, 0,   255);

  // let's verify that the value is now 0-255
  Serial.println(value);

  // and we can use it to fade an LED!
  analogWrite(ledPin, value);
}






