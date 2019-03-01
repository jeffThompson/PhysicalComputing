
/*
  ANALOG INPUT (reading a potentiometer)
  Jeff Thompson | 2019 | jeffreythompson.org

  Analog inputs let us read a wide variety of sensors into the
  Arduino, getting us more fine-grained control as well as
  values that can change over time. The Arduino Uno has a total
  of 6 analog input pins.

  For this example, we'll hook up a potentiometer (a "knob", also)
  called a "pot") that gives us a varying analog value as you turn
  it. For wiring up other sensors, we'll need a circuit called a 
  "voltage divider," which is covered in the next example.

  CHALLENGES:
  1. Can you combine the pot circuit with a button, so that the LED
     only blinks when the button is pressed?

*/

int sensorPin = A0;   // pot input on analog pin #1
int ledPin =    13;   // LED on pin 13


void setup() {
  Serial.begin(9600);

  // set our LED pin to output
  pinMode(ledPin, OUTPUT);

  // note! all analog pins on the Arduino are input-only*
  // so we don't have to use pinMode() for them

  // *technically, they can also be used as digital outputs:
  //  https://www.arduino.cc/en/Tutorial/AnalogInputPins
}


void loop() {

  // read the potentiometer value
  // and print to the Serial Monitor
  int value = analogRead(sensorPin);
  Serial.println(value);

  // note the values returned are in the range of 0–1023
  // this is because our input has 10 bits of resolution
  // since a bit has two possible values (either 0 or 1)
  // 10 bits means a range of 2^10 or 1024 possible values

  // we can use this value to change the blink rate of an LED
  digitalWrite(ledPin, HIGH);
  delay(value);
  digitalWrite(ledPin, LOW);
  delay(value);
  
}

