
#include <Servo.h>

/*
  SERVO MOTOR: AUTO ROTATE
  Jeff Thompson | 2019 | jeffreythompson.org

  We can also program our servo motors to do complex movements
  all on their own! This can be useful for things like having
  a button press trigger the servo to move or even more complicated
  systems like drawing machines.

  In this example, our servo does a little "wag" in the setup, then
  moves back-and-forth repeatedly in the loop.

  MORE SERVOS!
  The Arduino boards can handle up to 12 servos at once, which is super
  cool. You may run into issues powering your board over USB, though.
  If you want to use more than about 2 servos, you should consider
  an external power supply (anything that provides 7–12 volts DC and 
  about 1-1.5 amps should be ok).

  CHALLENGES:
  1. You may notice that the servo's 90º position isn't always dead
     center. This is due to how they're manufactured, but try tweaking
     your code to accommodate! (Hint: test to find the right angle and
     create a variable called "center".) You may want to do the same
     thing for 0 and 180º as well.
  2. Try connecting two or more servos to your Arduino and give them 
     different behaviors. You'll need to create multiple instances of
     the Servo library, so consider giving the motors more descriptive
     names.

*/


int servoPin = 9;   // motor connected on digital pin 9

int pos = 0;        // keep track of servo position
Servo servo;        // servo object from library


void setup() {

  // connect ("attach" the servo on selected pin)
  servo.attach(servoPin);

  // our servos can move from 0-180º with reasonably
  // precise control – give them an angle and the motor
  // will move to that position as fast as possible
  servo.write(90);    // move to 90º (center of rotation)
  delay(200);         // wait a bit for the motor to get into position
  servo.write(45);    // move counter-clockwise
  delay(200);
  servo.write(135);   // move clockwise
  delay(400);
  servo.write(90);    // and back to center
  delay(2000);        // wait 2 sec before starting loop()

  // some servos are "continuous rotation" meaning they
  // can go around 360º and beyond – with these motors,
  // the write() command sets the speed, making them great
  // for when you need slow movement but much harder if
  // you need accurate angles – be careful when shopping!
}


void loop() {

  // move from 0 to 180º, one degree at a time
  // using delay() to control the speed
  for (pos=0; pos<=180; pos+=1) {
    servo.write(pos);
    delay(15);          // try changing this and see what happens!
  }

  // wait 500ms before going back
  delay(500);

  // go back from 180 to 0º
  for (pos=180; pos>=0; pos-=1) {
    servo.write(pos);
    delay(15);
  }

  // and wait again before starting the loop again
  delay(500);
}


