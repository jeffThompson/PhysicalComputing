'''
INTERNAL LED
Jeff Thompson | 2022 | jeffreythompson.org

We'll get into sensors and circuits and all kinds of exciting stuff, but the Physical Computing equivalent of 'Hello world' is blinking an LED!

Light-emmitting diodes (LEDs) are everywhere: they're cheap, bright, come in lots of colors, are super easy to wire up, and are pretty hard to fry :)

For this first example, we'll use the LED that's built into your Feather board – even easier! You'll find the LED next to the USB connection near the label '13'.
'''

'''
LIBRARY IMPORTS
Before we can do anything, we need to add some extra code to our project. Called 'libraries,' these give us extra functionality, such as controlling the inputs and outputs on our board. These three imports will be used in every project you make this semester...
'''
import board      # access the board itself
import digitalio  # access input/output on board
import time       # utility for time-related stuff

'''
SET UP LED
In this example, we don't have to actually wire anything up. But we do have to tell our board where to find the LED and that this should be an output. (Buttons, as we'll see next week, are an example of an input.)

First, we create a variable for our LED using the built-in LED pin (#13)...
'''
led = digitalio.DigitalInOut(board.LED)

# ...then we tell it this is an output pin
led.direction = digitalio.Direction.OUTPUT

# then blink forever!
while True:
    led.value = True       # turn on LED
    time.sleep(0.5)        # pause the program for 1/2-sec
    led.value = False      # turn off
    time.sleep(0.5)        # and pause again

'''
Save the code to your board and you should see the red LED blink... awesome!

CHALLENGES:
1. Try changing the time.sleep() values above to see how it changes the blink rate
2. Try ejecting the board from your computer: what happens? Why do you think that happens?
'''

