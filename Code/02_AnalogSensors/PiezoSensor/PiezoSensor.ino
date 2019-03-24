
/*
  PIEZO SENSOR
  Jeff Thompson | 2019 | jeffreythompson.org

  The piezo sensor is particularly amazing: it can detect
  the tiniest of vibration! You can attach it to an object, 
  even beneath the surface, and watch it pick up tapping,
  knocking, or even scratching sounds.

  Made of a brass disc coated with a ceramic material, the
  piezo (short for "piezoelectric") disc generates electricty
  when deformed by sound waves, making it a very cheap but
  very sensitive sensor.

  (Piezo discs are also used in the reverse: as speakers!)

  In this example, we hook up a piezo disc as an analog sensor
  and use it to toggle an LED on and off. The sensitivity is
  set by a variable called "threshold" – higher value = harder
  to trigger, lower = easier to trigger but more susceptible
  to noise.

*/


int threshold = 30;    // values above this will trigger the led

int sensorPin = A0;     // piezo sensor on analog pin 0
int ledPin =    13;     // led will turn on/off with piezo
boolean ledState = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  // read the piezo sensor, print the value
  int value = analogRead(sensorPin);
  Serial.println(value);

  // if the reading is above the threshold set above...
  if (value > threshold) {
    
    // toggle the led state variable
    // (! means "not" -- not true = false, not false = true)
    ledState = !ledState;

    // and write the state to the led
    digitalWrite(ledPin, ledState);
  }

  // delay a small amount to avoid overloading
  // the Serial Monitor
  delay(50);
}


