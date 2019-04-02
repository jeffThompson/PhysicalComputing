
/*
  STEPPER MOTOR
  Jeff Thompson | 2019 | jeffreythompson.org

  Stepper motors offer tons of control to your project! Unlike a DC
  motor they can be easily made to spin slowly and in precise amounts;
  unlike servo motors they can move around in full circles! The down-
  side is that stepper motors require a "driver board" with more complex
  circuitry to run – the EasyDriver board from Sparkfun is very good
  and (reasonably) cheap: https://www.sparkfun.com/products/12779

  Since we can carefully control the stepper's movement, they're great
  for things like building your own CNC machine, especially for non-
  standard uses: think drawing machines, musical robots, etc!

  More info on hooking up your stepper motor:
  https://learn.sparkfun.com/tutorials/easy-driver-hook-up-guide

  HOW ACCURATE ARE THEY?
  Most stepper motors are 1.8º per step, meaning that for every step
  you ask the motor to turn, the shaft rotates 1.8º... or 200 steps
  per full revolution. Not bad, but the "microstep" code below lets
  us get 8-times that resolution, or 0.225º per step!

  WANT MORE CONTROL?
  +  For more complex functionality like acceleration try the 
     AccelStepper library
  +  To build a device that will work with standard CAD/CAM software,
     take a look at GRBL-compatible boards like this one:
     https://www.sparkfun.com/products/13899

  CHALLENGES:
  1. Can you use variables for the motor's direction? This will let
     your code be more semantic (easier to understand as text) and
     intuitive to control. (Hint: declare them as keywords just like
     OUTPUT and INPUT_PULLUP! const int FORWARD = LOW; and 
     const int BACKWARD = HIGH;)
  2. A common addition to a CNC machine is an end-stop – basically a
     switch that tells the machine where its endpoints are. Building
     a full CNC machine with belts, linear motion, etc is very complex,
     but can you wire up an end-stop switch and make the motor stop
     when it's pressed?
  
*/


int stepPin =       9;   // pin to trigger the motor to move a step
int directionPin =  8;   // pin to set the direction the motor will move

int microstepPin1 = 4;   // two pins that allow us to go into "microstep"
int microstepPin2 = 5;   // move (see code below for an explanation)


void setup() {

  // set all pins to output
  pinMode(stepPin,       OUTPUT);
  pinMode(directionPin,  OUTPUT);
  pinMode(microstepPin1, OUTPUT);
  pinMode(microstepPin2, OUTPUT);

  // make sure the motor starts "off"
  digitalWrite(directionPin, LOW);
  digitalWrite(stepPin,      LOW);

  // optional: go into "small step" mode
  // which gives us better resolution from our stepper
  // try this and see how the motor's movement changes!
  // enableSmallStepMode();
}


void loop() {

  // set direction of motor to forward
  digitalWrite(directionPin, HIGH);

  // turn the motor 1000 steps (one full revolution)
  for (int i=0; i<1000; i++) {

    // trigger a new step – this happens when the
    // stepPin goes from LOW to HIGH so when we're
    // done we set it LOW again to it can be retriggered
    digitalWrite(stepPin, HIGH);
    delay(1);         
    digitalWrite(stepPin, LOW);
    delay(1);         
  }
  delay(500);

  // step backward too!
  digitalWrite(directionPin, LOW);
  for (int i=0; i<200; i++) {
    digitalWrite(stepPin, HIGH);
    delay(1);         
    digitalWrite(stepPin, LOW);
    delay(1);         
  }
  delay(500);
}


// by setting the two microstep pins HIGH we can make each
// step from the motor move a smaller amount – the result will
// be slower but more accurate movement!
void enableSmallStepMode() {
  digitalWrite(microstepPin1, HIGH);
  digitalWrite(microstepPin2, HIGH);
}



