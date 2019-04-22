
#include <CapacitiveSensor.h>

/*
  CAPACITIVE TOUCH
  Jeff Thompson | 2019 | jeffreythompson.org

  Mechanical buttons are cool but touch sensors are really cool!
  Complex touch sensing like your phone's screen, which gives
  x/y position is very complex, but simple touch is actually really
  easy and can even approximate how close you are to the sensor.

  A surface with a conductive material like aluminum foil or copper
  tape works great and only requires a single wire, plus two
  digital pins and a 1M-ohm resistor. So easy!

  Requires the CapacitiveSensor library from Paul Stoffregen:
  https://github.com/PaulStoffregen/CapacitiveSensor

  More info:
  https://playground.arduino.cc/Main/CapacitiveSensor

  CHALLENGES:
  1. This kind of sensor would definitely benefit from some
     smoothing! Can you implement the smoothing code from the
     AnalogSensor project here?
  2. If you vary the resistor value you can make your sensor more
     or less sensitive, even allowing you to hide the sensor under
     up to 1/4" (3mm) of plastic or wood. Try a 10M-ohm resistor
     and see if you can make a hidden version!

*/

int touchRecPin =     4;        // pin connected to your touch sensor
int touchSendPin =    3;        // pin *not* connected to your sensor
int ledPin =          5;        // PWM pin to show sensor reading

int minThreshold =    50;       // a min reading when not touched
int maxTouchReading = 2000;     // max reading when fully touched near the wire
                                // (you'll need to test with your sensor)

// init our sensor – the library does all the hard work!
CapacitiveSensor touchSensor = CapacitiveSensor(touchSendPin, touchRecPin);


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {

  // read the sensor's value and print to Serial Monitor
  // 30 = number of samples to test before giving a value
  // higher = less jittery but will slow your sketch
  // lower = faster but more noise
  int touchValue = touchSensor.capacitiveSensor(30);
  Serial.println(touchValue);

  // if we're not touching, turn off the LED
  if (touchValue < minThreshold) {
    digitalWrite(ledPin, LOW);
  }

  // if we are, scale the reading to a brightness value
  // and turn on the LED!
  else {
    int brightness = map(touchValue, 0, maxTouchReading, 0, 255);
    brightness = constrain(brightness, 0, 255);
    analogWrite(ledPin, brightness);
  }
}


