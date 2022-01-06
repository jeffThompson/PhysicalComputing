
/*
  MESSAGES TO OTHER SOFTWARE
  Jeff Thompson | 2019 | jeffreythompson.org

  The Arduino alone can do some pretty cool things, but we
  can also get it to play nicely with other applications. To
  do that, we need some way for the two programs to communicate
  with each other. If paired with Processing, this is super
  easy: we just send a value over Serial as if printing to the
  Serial Monitor, then capture that in Processing! To connect
  with Max/MSP, a popular graphical programming language for
  music, it takes a little more doing but is also super
  easy.

  WHAT ABOUT OSC?
  You might have heard about Open Sound Control, or OSC, which
  lets you send complex message throughout your computer. When
  it works, it's amazing, but it can be a bear to get there.

*/

int sensorPin = A0;   // a pot or other sensor

void setup() {

  // start a serial connection (note the "baud rate"
  // of 9600 must match your Processing sketch.Max patch)
  Serial.begin(9600);
}


void loop() {

  // read the potentiometer
  int brightness = analogRead(sensorPin);

  // send its value over serial... just like printing
  // to Serial Monitor!
  Serial.println(brightness);

  // wait a bit to avoid overloading your other application
  delay(20);

  // what about multiple sensors?
  // if you wanted to send more than one sensor value, try
  // sending them one-by-one as a single message, delineating
  // them with a comma and ending the message with println()

  // int pot1 = analogRead(A0);    // read two sensor values
  // int pot2 = analogRead(A1);
  // Serial.print(pot1);           // print one (no newline!)
  // Serial.print(",");            // print a comma
  // Serial.println(pot2);         // end of message

  // note: this will require fancier parsing on the other
  // end to split the individual sensor readings
}


