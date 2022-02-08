# TYPING STRINGS

Sending a single key when the button is pressed mimics a normal keyboard, but that's not all we can do! The `HID` library also lets us send [strings](https://en.wikipedia.org/wiki/String_(computer_science)) (a set of characters, like a word or sentence) with only a single button. (Of course, we could do this letter-by-letter using the previous example, but that would be super messy.)

We'll need to use an additional library for this, but it's already included in the `HID` folder we added in the last example. The button setup is the same too, so we'll just jump into the code!

***

### CONTENTS  

* [Basic setup](#basic-setup)  
* [Sending strings](#sending-strings)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)  

### STUFF YOU'LL NEED  

* One pushbutton  
* Jumper wires  
* Feather board  
* USB cable  

***

### BASIC SETUP   
First, we'll create the button, LED, and keyboard, just like before:

```python
import board
import digitalio
import time

from adafruit_debouncer import Debouncer

import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

pin = digitalio.DigitalInOut(board.D5)
pin.pull = digitalio.Pull.UP
button = Debouncer(pin)

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

time.sleep(1)
keyboard = Keyboard(usb_hid.devices)
```

We also need to add this line:  

```python
keyboard_layout = KeyboardLayoutUS(keyboard)
```

This is required for us to send strings instead of individual key presses. Since keyboards for different languages (and even different regions) have [different layouts](https://en.wikipedia.org/wiki/Keyboard_layout), we need to tell the Feather which one to use so it sends the right keys. This example uses a US layout, since that's where I'm based. 

> 🙋‍♀️ What about other languages or countries? The library appears to work with other layouts too, but I don't have a good way to test this, sorry! You can [try following these instructions](https://github.com/Neradoc/Circuitpython_Keyboard_Layouts). If you have success, please let me know and I will update this tutorial!

***

### SENDING STRINGS  
With our setup done, let's send some text! This is super easy with the `write()` command:

```python
keyboard_layout.write('hello')
```

We don't need the `release_all()` command after, since the library handles all this for us. Let's combine this with the button code and some regular key presses:

```python
while True:
  button.update()
  
  if button.rose:
    led.value = False
  
  if button.fell:
    led.value = True
    
    # write something
    keyboard_layout.write('hello')
    keyboard.press(Keycode.RETURN)
    keyboard.release_all()
    
    # then write something else, feel
    # sheepish, then delete it
    keyboard_layout.write('farts')
    
    # add some delays throughout to 
    # make it more realistic
    time.sleep(0.5)
    for i in range(0, 5):
        keyboard.press(Keycode.BACKSPACE)
        time.sleep(0.1)
        keyboard.release_all()
```

If you push the button, you should see the word `hello` appear, then your cursor will go down to a new line by sending the return key. After that it prints a word then deletes it letter-by-letter. All these commands happen super quick, but we can use `time.sleep()` to simulate a person typing.

***

### FULL CODE EXAMPLE  

```python
import board
import digitalio
import time

from adafruit_debouncer import Debouncer

import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

pin = digitalio.DigitalInOut(board.D5)
pin.pull = digitalio.Pull.UP
button = Debouncer(pin)

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

time.sleep(1)
keyboard = Keyboard(usb_hid.devices)

while True:
  button.update()
  
  if button.rose:
    led.value = False
  
  if button.fell:
    led.value = True
    
    # write something
    keyboard_layout.write('hello')
    keyboard.press(Keycode.RETURN)
    keyboard.release_all()
    
    # then write something else
    # and then delete it
    keyboard_layout.write('farts')
    
    # add some delays throughout to 
    # make it more realistic
    time.sleep(0.5)
    for i in range(0, 5):
        keyboard.press(Keycode.BACKSPACE)
        time.sleep(0.1)
        keyboard.release_all()

```

***

### CHALLENGES  

1. Can you find a poem or song lyrics that you like and have it type out when the button is pressed? Can you add delays (or even randomized ones!) to simulate a person typing?  
2. Sending strings to a text editor is pretty alright, but can you think of other places where typing text would be helpful or fun? Think about all the ways you use your keyboard on a regular basis  

