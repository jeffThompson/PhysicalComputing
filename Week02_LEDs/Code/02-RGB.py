'''
RGB LED (aka NeoPixel)
Jeff Thompson | 2022 | jeffreythompson.org

'''

built-in rgb led
- first, try 'import neopixel'
  - error!

- install the neopixel lib
- https://circuitpython.org/libraries
- download 'bundle' for 7.x
- look inside for lib folder
  - inside that for neopixel.mpy
- copy that file to the lib folder on your board

import board
import time
import neopixel

led = neopixel.NeoPixel(board.NEOPIXEL, 1)

# (1 in the command above means only 1 LED)

led.brightness = 0.1
# 1 = full brightness, 0 = off

while True:
    led.fill( (255, 0, 0) )
    time.sleep(0.5)
    
    led.fill( (0, 255, 0) )
    time.sleep(0.5)
    
    led.fill( (0, 0, 255) )
    time.sleep(0.5)