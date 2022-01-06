
/*
  LED: BASIC
  Jeff Thompson | 2018 | Jeffreythompson.org

  As our first real sketch, we can turn an LED on and off. 
  Not super exciting, but this will cover many of the things
  used to build way more complex projects.

  WHAT IS AN LED?
  An LED (light-emitting diode) is a simple and ubiquitous
  device. Inside the plastic dome is a tiny semiconductor, 
  which lights up when small amounts of electricity flow
  through it.

  Important! Like some other components, LEDs have "polarity"
  meaning they must be wired in a certain orientation. Most
  LEDs are pretty forgiving, so if it doesn't light up as
  you expect, pull it out quickly and it should be ok.

  The long leg on the LED goes to positive, the short to ground.

  CIRCUIT:
  None! Your Arduino has a built-in LED that connects to digital
  pin 13, which you can use without any additional parts.
  
  Optionally, you can plug the long leg of your LED into digital 
  pin 13, negative into the ground pin next to it.

  CAVEAT:
  This isn't an electrical engineering course, and sometimes
  we'll be doing things in a way that's easier but not
  technically correct. Our LEDs really shouldn't be getting
  the full 5 volts from the Arduino. For our purposes it's
  probably ok, but usually we'd use a resistor (a small
  component that restricts the flow of electricity) to reduce
  the amount of power the LED is getting.

  TLDR: more electricity = brighter LED but possibly shorter
  life, or it could burn out immediately

  CHALLENGES:
  1. Try changing the timing of the blink or create
     more complex patterns with multiple HIGH/LOW commands
  2. Can you wire up more LEDs to your Arduino using your
     breadboard?

*/

void setup() {

  // tell the Arduino that the LED, attached
  // to digital pin #13, is an output
  // (later, we'll hook up a button as an input)
  pinMode(13, OUTPUT);
}


void loop() {

  // turn the LED on and wait 500 milliseconds
  digitalWrite(13, HIGH);
  delay(500);

  // turn it off, wait another 500 milliseconds
  digitalWrite(13, LOW);
  delay(500);
}

