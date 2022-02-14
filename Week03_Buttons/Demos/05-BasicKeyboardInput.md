# BASIC KEYBOARD INPUT

With the wiring and code for button input sorted, let's put it to use! Our Feather boards aren't just capable to sending data to Mu Editor, we can also have them act as a keyboard. Buttons can trigger key presses, as we'll see in this example, as well as more complex stuff too!

***

### CONTENTS  

* [Required libraries](#required-libraries)  
* [Basic setup](#basic-setup)  
* [Keyboard input](#keyboard-input)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)  

### STUFF YOU'LL NEED  

* One pushbutton  
* Jumper wires  
* Feather board  
* USB cable  

***

### REQUIRED LIBRARIES  
In order to have our Feather act as a keyboard, we need some additional code libraries. By this point, you should know how to install them; if you need a refresher, check the [`Debouncing` example](02-Debouncing.md).

You'll want drag the entire `adafruit_hid` folder to your board. Just grab the whole folder, no need to manually add the files in there!

`HID` stands for [*human interface device*](https://en.wikipedia.org/wiki/Human_interface_device). This means our Feather can act like a keyboard, a mouse, and even a media remote control for things like volume.

***

### BASIC SETUP  
These examples will use a single button on `D5`, which you may already have wired up from the previous examples. We'll also use the `Debouncer` library for handling the button input.

First, let's import the usual libraries:

```python
import board
import digitalio
import time

from adafruit_debouncer import Debouncer
```

Followed by the `HID` libraries:

```python
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
```

Now's a good time to run your program and verify the libraries are installed correctly. Next, we can set up the button and LED:

```python
pin = digitalio.DigitalInOut(board.D5)
pin.pull = digitalio.Pull.UP
button = Debouncer(pin)

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
```

***

### KEYBOARD INPUT  
With our button all set, we next need to create a `keyboard` object in our code. We'll use this to send key presses to our computer.

```python
time.sleep(1)
keyboard = Keyboard(usb_hid.devices)
```

> 🙋‍♀️ What's that `time.sleep()` command doing there? Think about what happens when you connect your Feather to your computer. The Feather turns on super fast, but there may be a slight lag while your computer establishes a USB connection. If we try to send keyboard commands before that's finished, our code will crash and we won't be able to do anything... bummer! Adding a one-second delay allows everything to sync up, so it's really just a safety. You might be able to come up with a clever way to wait until the USB connection is ready, but this hack should work too.

Next, we'll read the button's state and trigger the `x` key when it's pressed. Remember that, because of the way our button is wired, `fell` means it's pressed:

```python
while True:
  button.update()

  # if button released, turn off led
  if button.rose:
    led.value = False

  # if button pressed
  if button.fell:
    keyboard.press(Keycode.X)
    keyboard.release_all()
    led.value = True
```

When the button is pressed, we first call the `press()` command using the keyboard object. The library uses a set of variables for each key, including the letters and numbers but also the spacebar and all other keys too. A full list of the key codes used in the library can be found on the [Circuit Python `HID` reference](https://circuitpython.readthedocs.io/projects/hid/en/latest/api.html#adafruit-hid-keycode-keycode).

But we also need to let go of the key! Otherwise, we'd see `xxxxxxxx...` over and over forever. `release_all()` will release any key that's being pressed by our software. Generally, any time you trigger a key press you should immediately use `release_all()`.

Try saving the code to your board, opening a text editor, web browser, etc and then press the button. You should see an `x` printed. Press the button again, another `x`!

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

# set up the button on D5
pin = digitalio.DigitalInOut(board.D5)
pin.pull = digitalio.Pull.UP
button = Debouncer(pin)

# and the internal LED too
led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

# don't start the program too quick!
# can cause an error while your computer
# connects to the Feather board
time.sleep(1)
keyboard = Keyboard(usb_hid.devices)

while True:
  button.update()

  # if button released, turn off led
  if button.rose:
    led.value = False

  # if button pressed
  if button.fell:
    keyboard.press(Keycode.X)
    keyboard.release_all()
    led.value = True
```

***

### CHALLENGES  

1. Look at the different key codes in the reference. Try having the keyboard send different characters!  
2. Can you wire up a second button and have it press a different character?  
3. Can you have a `count` variable go up every time the button is pressed, then have it send that value as a key press? (Hint: `count` will probably have to reset when it reaches 10, since there's no key for that.)

