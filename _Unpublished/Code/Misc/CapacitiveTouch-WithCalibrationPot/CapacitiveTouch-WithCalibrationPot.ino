
#include <CapacitiveSensor.h>

/*
  CAPACITIVE TOUCH (with calibration pot)
  Jeff Thompson | 2019 | jeffreythompson.org

  A slightly fancier version of the CapacitiveTouch example,
  this time using a potentiometer to calibrate the sensor.
  Try adjusting the pot until, when not near the sensor, the
  LED goes off!

  See that example for more info how how to setup and read the 
  touch sensor.

*/

int touchRecPin =     4;        // pin connected to your touch sensor
int touchSendPin =    3;        // pin *not* connected to your sensor
int ledPin =          5;        // PWM pin to show sensor reading
int potPin =          A0;       // pin to read the potentiometer

int maxTouchReading = 2000;     // max reading when fully touched near the wire

CapacitiveSensor touchSensor = CapacitiveSensor(touchSendPin, touchRecPin);


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {

  // read potentiometer and use that value to set a min threshold
  // for the sensor
  int potValue = analogRead(potPin);
  int minThreshold = map(potValue, 0,1023, 0,maxTouchReading);

  // read the touch sensor
  int touchValue = touchSensor.capacitiveSensor(30);
  Serial.println(touchValue);

  // if we're not touching, turn off the LED
  if (touchValue < minThreshold) {
    digitalWrite(ledPin, LOW);
  }

  // if we are, scale the touch sensor reading to a brightness 
  // value and turn on the LED!
  else {
    int brightness = map(touchValue, 0, maxTouchReading, 0, 255);
    brightness = constrain(brightness, 0, 255);
    analogWrite(ledPin, brightness);
  }
}


