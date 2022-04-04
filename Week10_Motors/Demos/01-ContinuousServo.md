# CONTINUOUS SERVO MOTOR
In the [last example](00-ServoMotor.md), we saw how to connect and rotate a "standard" servo motor. A "continuous" servo works almost exactly the same way, except that we don't set the angle but instead tell the motor what direction to rotate and how fast to do so. This works great for simple robots and other machines, but doesn't give us the same repeatable precision that a standard servo does.

***

### CONTENTS  

* [Connecting the servo](#connecting-the-servo)  
* [Making it rotate](#making-it-rotate)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)

### STUFF YOU'LL NEED  

* "Continuous" servo motor  
* Jumper wires  
* Feather board  
* USB cable  

***

### CONNECTING THE SERVO  
This is exactly the same as with the standard servo! Check the [previous example](00-ServoMotor.md#connecting-the-servo) for details.

***

### MAKING IT ROTATE  
The code setup for a continuous servo is nearly the same too. We import the same libraries, set up a PWM pin, then create the motor:

```python
import board
import pwmio
import time
from adafruit_motor import servo

pin = pwmio.PWMOut(
  board.D5, 
  duty_cycle = 2**15, 
  frequency = 50
)
motor = servo.ContinousServo(pin)
```

You'll notice the only difference here is that we make a `ContinousServo` object instead of just a `Servo`. We're all set!

To rotate the servo, we give it a value called `throttle` between `–1 and 1`:

| THROTTLE | DIRECTION         | SPEED |
|----------|-------------------|-------|
| 1        | Clockwise         | 100%  |
| 0.5      | "                 | 50%   |
| 0        | Stopped           | n/a   |
| -0.5     | Counter-clockwise | 50%   |
| -1       | "                 | 100%  |

We can combine this with `time.sleep()` to set the speed and how long it should rotate for. For example:

```python
# clockwise at full speed for 1-second
motor.throttle = 1
time.sleep(1.0)

# stop the motor, wait for 1/2-second
motor.throttle = 0
time.sleep(0.5)

# counter-clockwise at 1/4 speed for 2-seconds
motor.throttle = -0.25
time.sleep(2.0)
```

Getting exact position using a continuous servo will be ~difficult~ basically impossible. Think about this more like the wheel of a car: you don't count rotations or duration to figure out how far you've gone! Instead, think about additional ways of figuring out the position such as a photo-interrupt or hall effect sensor.

***

### FULL CODE EXAMPLE  

```python
import board
import pwmio
import time

from adafruit_motor import servo

pin = pwmio.PWMOut(
  board.D5, 
  duty_cycle = 2**15, 
  frequency = 50
)
motor = servo.ContinousServo(pin)

while True:
  # clockwise at full speed for 1-second
  motor.throttle = 1
  time.sleep(1.0)

  # stop the motor, wait for 1/2-second
  motor.throttle = 0
  time.sleep(0.5)

  # counter-clockwise at 1/4 speed for 2-seconds
  motor.throttle = -0.25
  time.sleep(2.0)
```

***

### CHALLENGES  

1. Can you make the motor rotate in one direction while increasing in speed, then do the same in the opposite direction?  

