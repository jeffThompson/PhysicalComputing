'''
EXTERNAL LED
Jeff Thompson | 2022 | jeffreythompson.org

'''

external led!
- connect long leg to 5
- short to gnd

import board
import time
from digitalio import DigitalInOut, Direction

led = DigitalInOut(board.D5)

led.direction = Direction.OUTPUT

while True:
    led.value = True
    time.sleep(0.5)
    
    led.value = False
    time.sleep(0.5)