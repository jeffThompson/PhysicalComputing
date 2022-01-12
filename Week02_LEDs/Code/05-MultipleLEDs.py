'''
MULTIPLE LEDs
Jeff Thompson | 2022 | jeffreythompson.org

'''

multiple leds!
- note on limits re current

import board
import time
from digitalio import DigitalInOut, Direction

led1 = DigitalInOut(board.D5)
led2 = DigitalInOut(board.D6)

led1.direction = Direction.OUTPUT
led2.direction = Direction.OUTPUT

while True:
    led1.value = True
    led2.value = False
    time.sleep(0.5)
    
    led1.value = False
    led2.value = True
    time.sleep(0.5)