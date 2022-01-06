
#include <Servo.h>      // import library for servo control

/*
  SERVO MOTOR: BASICS
  Jeff Thompson | 2019 | jeffreythompson.org

  Servo motors are excellent for exact rotational positioning,
  letting you do things like move a rod back-and-forth or
  control the arms of a puppet. Servos come in a variety of
  sizes and strengths, from tiny "micro" servos to huge ones
  used in industrial robots. The servo requires three wires:
  one for power, one for ground, and one that sends a digital
  signal that tells the servo what position to move to.

  In this simple example, we use a potentiometer to change
  the angle of the servo – essentially a remote control!

  HOW DO THEY WORK?
  Servos are actually super simple! Inside the plastic case is
  a really cheap motor, some gears (which slow the motor's
  movement and give us more torque), and a little controller
  board with the magic ingredient: a potentiometer! The pot
  is connected to the motor's shaft, letting us get feedback
  on its exact position. This combination of parts makes
  servos really cheap and easy to use compared to other options
  like stepper motors.

  Want to see inside? Check out:
  https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-
  motors/inside-a-servo

  Cheaper servos have plastic gears, but for longer life or
  heavier loads, all-metal servos are the way to go. Check
  Amazon for servos used in RC cars and airplanes as a good
  source. Fancier (ie $$) servos are made of heavy-duty
  materials and can even be chained together! See these
  ones from Trossen Robotics as an example:
  https://www.trossenrobotics.com/robot-servos

*/

int servoPin = 9;   // motor connected on digital pin 9
int potPin =   A0;  // potentiometer on analog pin 0

Servo servo;        // servo object from library


void setup() {

  // connect ("attach" the servo on selected pin)
  servo.attach(servoPin);
}


void loop() {

  // read the potentiometer value and map it to the
  // range of our servo (0-180º)
  int value = analogRead(potPin);
  value = map(value, 0,1023, 0,180);

  // tell the servo to go to that angle and wait a moment
  // for it to get there
  servo.write(value);
  delay(15);
}


