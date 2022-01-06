
/*
  BUTTON INPUT: STATE CHANGE
  Jeff Thompson | 2018 | jeffreythompson.org

  Our simple button sketch works well, but if we hooked
  it up to the Serial Monitor we'd see that it prints the
  button's state continuously. If we only want to trigger
  something when the button changes from HIGH to LOW or
  vice versa, we need to ignore repeated values.

  This is similar to the idea of "debouncing," which further
  helps with the messy, in-the-world fact that switches are
  mechanical devices. See this example for more info:
  https://www.arduino.cc/en/Tutorial/Debounce

  CHALLENGES:
  1. Can you write code so that pressing the button down
     toggles an LED on and off? In other words, press the button
     once to turn the LED on, press it again to turn it off.
     (Hint: you'll need to keep track of the button's state
     AND the LED's state too.)

*/

// we need to keep track of the previous state of the button
// which we can do using a variable
int previousState = LOW;


void setup() {
  Serial.begin(9600);         // start a serial connection over USB
  pinMode(2, INPUT_PULLUP);   // button on digital pin 2 using INPUT_PULLUP
}


void loop() {

  // read the button's current state
  int current = digitalRead(2);

  // if it's not equal to the previous state...
  if (current != previousState) {
    Serial.println(current);        // ...print the value
    previousState = current;        // and set the previous state to the current one
  }

  // a slight delay to avoid overwhelming
  // the Serial Monitor
  delay(10);
}

