
/*
  PRINTING MESSAGES
  Jeff Thompson | 2018 | jeffreythompson.org

  Debugging electronics can be much harder than code
  you run on your computer. The Arduino has no screen,
  but thanks to its built-in USB connection, we can
  send simple messages from the Arduino to the computer,
  which is helpful for testing whether a button is
  pressed or to see the value of a sensor.

  We can also send messages from the computer to the
  Arduino, which we'll look at later in the semester
  as a way to bridge the Arduino to other software,
  like a Processing sketch or Max/MSP.

  TO VIEW/SEND SERIAL MESSAGES:
  To see what the Arduino is sending and to send messages
  to it, click the magnifying glass icon in the upper-right
  for the Serial Monitor. Be sure to set the baud rate
  to what you've chosen below.

  Values sent from the Arduino will automatically be
  printed onscreen. To send values to the Arduino, type
  them in the text bar and hit return or the Send button.

  CHALLENGES:
  1. Can you use if/else statements to create a simple
     pre-programmed chat interface? Think about very simple
     text inputs and responses that the Arduino could send
     back.

*/

void setup() {

  // a button, connected on digital pin 2
  // using the internal pullup resistor
  pinMode(2, INPUT_PULLUP);

  // initiate a connection over serial (USB)
  // 9600 is the "baud rate", which we need to
  // match in the Serial Monitor window (otherwise
  // you'll get garbled madness
  Serial.begin(9600);

  // send an initial message
  Serial.println("Reading button state...");
}


void loop() {

  // read the pin into a variable
  int state = digitalRead(2);

  // send the value over USB to the Serial Monitor
  Serial.println(state);

  // we can also format our messages a little nicer
  // using the print() command (which doesn't include
  // a line-break)
  // Serial.print("- state: ");
  // Serial.println(state);

  // note: unlike programming languages like Java, we
  // can't combine values in the println() command using
  // the + symbol – instead, we need to use multiple
  // print() and println() commands to build the message

  // receiving messages from the Serial Monitor is also
  // possible – we won't go into too much detail now, but
  // this can be useful for sending complex commands to
  // your Arduino (instead of having a dozen buttons, for
  // example) or for bridging with other software

  // if there is new data being sent to the computer
  if (Serial.available() > 0) {
    int val = Serial.read();      // read the value...
    Serial.println(val);          // ...and print it
  }

  // all done sending and receiving data?
  // set a small delay at the end of the loop() to prevent
  // overloading the serial port
  delay(10);
}

