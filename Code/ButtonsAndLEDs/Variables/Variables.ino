
/*
  VARIABLES
  Jeff Thompson | 2018 | jeffreythompson.org

  We've already seen some variables in use, such as "int" when
  reading the value from a button, but we haven't talked about
  what that all means. (If you've already taken a programming
  course, you can skim this for Arduino-specific info.)

  Variables are placeholders for different values. They let us
  store numbers or text so we can later recall, updaet, or
  manipulate them.

  TYPES:
  Unlike lanugages like Python, C/C++ which Arduino is based
  on is "statically typed", meaning we have to specify what
  kind of value our variable holds. For the tiny memory that
  the board has, this becomes super important as your program
  grows: the difference between a byte and an int can start
  to add up. But for now, it will just be helpful to understand
  a few basics.

  Numbers:
  int       "integer", a whole number (no decimal)
  byte      a smaller integer, values between -255 and 255*

  Text:
  char      "character", a single letter noted with ''
  String    a series of characters, noted with ""

  Other:
  boolean   true or false, similar to 0/1 and LOW/HIGH

    In Arduino examples, you may see "unsigned" applied in front
    of some variables. This means no negative numbers and is used
    to save memory. For example, "unsigned byte" would be 0-255.

*/

// global variables
// these are values accessible anywhere in the program
// a good use is to save the pin for an LED or button
int ledPin =    13;
int buttonPin = 2;

// we can also use a global variable to keep track of
// something like the number of times a button is pressed
int count =     0;

// boolean values are also useful as "flags", ways to
// turn on/off features in your code or control flow
boolean printCount = true;

void setup() {
  Serial.begin(9600);

  // we can reference the led and button pin numbers here
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}


void loop() {

  // local variables
  // these are created within a particular context, but can't be
  // seen elsewhere in your code
  // for example, we can temporarily read in the state of a button
  int state = digitalRead(buttonPin);

  // if button is pressed, update the count value
  if (state == LOW) {
    count += 1;

    // if the "printCount" variable is true, write the current
    // number of button presses to the Serial Monitor
    if (printCount) {
      Serial.println(count);
    }
  }
}


