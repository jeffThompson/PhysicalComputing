
/*
  CONDITIONAL STATEMENTS
  Jeff Thompson | 2018 | jeffreythompson.org

  Blinking LEDs and reading buttons is great, but if we
  want more complex control we need to use conditional
  statements. These let us specify simple (and not-so-
  simple) rules that control the behavior of our code.

  SYNTAX:
  There are just a few symbols used in if/else statements:

  ==    equal             true if both values are the same, false if not
  !=    not equal         true if values are NOT the same, false if they are
  >     greater than      true if left value is greater than the right
  <     less than         true if left value is less than the right
  >=    greater or equal  true if left value is greater than or equal to the right
  <=    less or equal     true if left value is less than or equal to right
  &&    and               combine two or more statements, returns true if BOTH are true
  ||    or                combine two or more statements, returns true if EITHER are true

  We can chain these together as well for more complex tests.

  CHALLENGES:
  1. Can you create a more complex behavior with the two buttons and
     the LED using if/else statements?

*/

int buttonPin1 = 2;     // button attached to digital pin 2
int buttonPin2 = 3;     // and another to pin 3
int ledPin =     13;    // LED on pin 13


void setup() {
  Serial.begin(9600);

  // pin setup
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // some examples...
  // (they don't really do anything, but open Serial Monitor 
  // to see the result)

  // the simplest check: compare if two values are 
  // equal, print the result to the Serial Monitor
  int a = 0;
  int b = 3;
  if (a == b) {
    Serial.println("A equals B");
  }

  // tell us which value is greater than the other
  // if the "if" statement is false, "else" will get run, otherwise
  // it gets skipped
  int c = 0;
  int d = 1;
  if (c > d) {
    Serial.println("C is greater than D");
  }
  else {
    Serial.println("D is greater than C");
  }

  // if A and C are equal AND B and D are too
  if (a==c && b==d) {
    Serial.println("A==C and B==D");
  }

  // if either A and C are equal OR B is greater than D
  if (a==c || b>d) {
    Serial.println("A==C or B>D (but we don't know which)");
  }

  // we do many checks too
  if (a==b) {
    // do something
  }
  else if (c==d) {
    // do something else
  }
  else if (a > b+c+d) {
    // do another thing
  }
  else {
    // if none of the above, do this
  }
}


void loop() {

  // a more useful example: check if two buttons are pressed at
  // the same time...

  // read both buttons
  int state1 = digitalRead(buttonPin1);
  int state2 = digitalRead(buttonPin2);

  // if both on, turn the LED on
  if (state1 == LOW && state2 == LOW) {
    digitalWrite(ledPin, HIGH);
  }
  
  // if one is on and not the other, or both are off,
  // turn the LED off
  else {
    digitalWrite(ledPin, LOW);
  }
}

