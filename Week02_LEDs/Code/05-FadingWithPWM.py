'''
FADING WITH PULSE WIDTH MODULATION (PWM)
Jeff Thompson | 2022 | jeffreythompson.org

'''

import time
import board
import pwmio
from math import floor

# set up our LED
led = pwmio.PWMOut(
    board.LED, 
    frequency=5000, 
    duty_cycle=0
)
# try board.LED instead!


# via: https://stackoverflow.com/a/929107/1167783
def scale(n, in_min, in_max, out_min, out_max, convert_to_int=False):
    val = (((n - in_min) * (out_max - out_min)) / (in_max - in_min)) + out_min
    if convert_to_int:
        val = int(val)
    return val

# let's test our function!
print(scale(0, 0,100, 0,65535, True))
print(scale(50, 0,100, 0,65535, True))
print(scale(100, 0,100, 0,65535, True))

while True:
    
    # go up in brightness from 0–maximum (which is 65545, the max 16-bit value or 2^16)
    # but that range doesn't make too much sense, so we can use a custom
    # function to scale the range to something better
    
    for i in range(100):
        led.duty_cycle = scale(i, 0,100, 0,65535, True)
        time.sleep(0.01)
    
    # then turn off and start again
    led.duty_cycle = 0
    time.sleep(0.5)

stretch: 
- two pwm leds (one up, one down?)
- randint value