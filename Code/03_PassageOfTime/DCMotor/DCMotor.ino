
/*
  DC MOTOR
  Jeff Thompson | 2019 | jeffreythompson.org

  DC motors (what most of us would call "normal" motors) come
  in a huge range of sizes, power needs, rotational speed, and
  torque. They are capable of everything from running little
  toys to spinning the wheels on cars.

  In this example, we send a speed command via the Serial Monitor
  to change the rate the motor spins! Try attaching a small piece
  of tape to the motor's shaft to make it easier to see.

  CIRCUIT
  We can't just turn our motor on and off from the Arduino. This
  is because the motor would likely pull too much current from our
  board, especialyl when starting up. A motor can also generate
  electricity when spun (that's how things like wind turbines work!)
  so we need some circuitry to protect the Arduino from receiving
  that current too. To accomplish this, we need a transistor which
  acts like a little switch, a diode to keep electricity flowing
  in only one direction, and a resistor which biases the transistor
  so it works the way we want it to. (More info in the Adafruit 
  tutorial linked below.)

  CONTROLLING SPEED
  One of the big challenges with small DC motors is that they
  spin really fast. Like, REALLY fast. Typical DC motors will
  be at least 1000 RPM if not more like 10,000! That's way too
  fast for most things we'll want to do. To solve this, we can
  use PWM just like we did with the LEDs: turn the motor on and
  off really fast which smooths out to be slower motion!

  WHAT ABOUT LARGER MOTORS?
  Larger motors would require considerably more care when designing
  the control circuit. For those cases, it's definitely best to buy a
  professionally-designed "driver circuit" which handles everything
  for you. Good examples include these from Sparkfun:

  https://www.sparkfun.com/products/14450   (small-ish motors)
  https://www.sparkfun.com/products/10182   (for beast-sized ones)

  BASED ON
  This tutorial is based on this one from Adafruit:
  https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors/overview

*/

int motorPin = 9;


void setup() {  
  pinMode(motorPin, OUTPUT);

  // start serial connection
  Serial.begin(9600);
  while (!Serial) {
    // wait until a serial connection is established
  }
  Serial.println("enter a speed from 0–255!");
}


void loop() {

  // when new data comes in over serial, set the motor speed!
  if (Serial.available()) {

    // parse the speed from text to an integer
    int speed = Serial.parseInt();

    // if speed is 0, turn off the motor
    if (speed == 0) {
      Serial.println("stopping motor");
      digitalWrite(motorPin, 0);
    }

    // if it's within range, set the motor's speed
    else if (speed <= 255) {
      Serial.print("setting motor speed to ");
      Serial.println(speed);
      analogWrite(motorPin, speed);
    }

    // if not 0-255, let us know
    else {
      Serial.println("speed out of range! 0-255 only, please");
    }
  }
}

