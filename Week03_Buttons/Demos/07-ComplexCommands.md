# COMPLEX COMMANDS

Sending a few keystrokes or some text is cool, but with a little planning you can have a single button trigger a whole series of events on your computer! You could create custom keyboard shortcut button, automate complex processes, or create (kind-hearted) pranks to play on your friends.

A great example is the [dedicated copy/paste keyboard](https://www.theverge.com/22761188/stack-overflow-the-key-copy-paste-review-price-release-date-keyboard) put out by the code Q&A site Stack Overflow. It started out as a joke, but now is an actual product! Not only does it do just one task, it's quite nicely designed too.

***

### CONTENTS  

* [Be careful!](#be-careful) ☠️  
* [Basic setup](#basic-setup)  
* [Planning things out](#planning-things-out)  
* [Turning our script into code](#turning-our-script-into-code)  
* [Controlling media keys](#controlling-media-keys)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)  

### STUFF YOU'LL NEED  

* One pushbutton  
* Jumper wires  
* Feather board  
* USB cable  

***

### BE CAREFUL!  
This kind of automation is super fun, but it's worth pausing for a moment to add one word of caution: once your key press code is triggered, it will continue to run as fast as possible and won't stop unless you unplug the Feather or hit the reset button!

If you're doing anything that might delete data, send texts or emails, or otherwise do things you might regret, take extra care. Actually, you should be super careful no matter what you're doing: an innocuous keyboard shortcut in one program might have disaterous consequences in another 🙀

With great power comes great responsibility!

***

### BASIC SETUP  
Just like the last two examples, we'll use a button and the `HID` library. If you haven't gotten that all ready yet, check the [`BasicKeyboardInput` example](05-BasicKeyboardInput.md) first!

***

### PLANNING THINGS OUT  
If we want to do something more complex, we'll want to first figure out all the steps involved. In this example, we'll open a web browser, type in a URL to YouTube, and play the video! This example will only work on a Mac, since it uses Spotlight to open the browser... sorry Windows and Linux users! That said, the basic process here will be similar no matter what task you want to automate.

First, let's put together a little "script" of the steps involved:

| ACTION            | WHAT IT DOES |
| ------------------| ----------- |
| `Command + space` | Open Spotlight |
| *Firefox.app*     | Type the name of the browser |
| (wait)            | A slight delay so Firefox can be found |
| `Return`          | Open Firefox |
| (wait)            | Let Firefox open |
| `Command + T`     | Open a new tab |
| (send URL)        | Using the `write()` command |
| `Return`          | To open the URL |
| (wait)            | While the page opens |
| *k*               | Shortcut to play YouTube videos |

Kind of complicated-looking but really just step-by-step of what we would do normally! 

Keyboard shortcuts for various applications will be helpful here, since we don't have mouse input. You can start with the menus in your app, but you might find more by looking in the Help menu or online reference.

***

### TURNING OUR SCRIPT INTO CODE  
Now comes the somewhat tedious task of turning our script above into code. Building this into a function would be a good idea, since it moves all the messy details out of our main loop. This helps keep our code tidier and will make updating easier.

```python
def do_it():
  # open spotlight
  # press command then spacebar in one command!
  keyboard.press(Keycode.COMMAND, Keycode.SPACEBAR)
  keyboard.release_all()
  time.sleep(0.5)

  # type 'Firefox.app'
  keyboard_layout.write('Firefox.app')
  time.sleep(1)

  # return to open the browser
  keyboard.press(Keycode.RETURN)
  keyboard.release_all()
  time.sleep(1)

  # new tab, with two keys like above
  keyboard.press(Keycode.COMMAND, Keycode.T)
  keyboard.release_all()

  # type url and open it
  keyboard_layout.write(url)
  keyboard.press(Keycode.RETURN)
  keyboard.release_all()

  # play the video
  time.sleep(2)
  keyboard.press(Keycode.K)
  keyboard.release_all()
```

You'll notice that in two places above we actually send two key presses at once. The `press()` command lets us specify two or more keys, separated by commas!

```python
keyboard.press(Keycode.COMMAND, Keycode.C)
```

This command would copy something to the clipboard, opening up a ton of possibilities for automated keyboard shortcuts!

It took me quite a bit of trial-and-error to get this working right, so I'd suggest adding a little bit and trying it before adding more.

***

### CONTROLLING MEDIA KEYS  
In addition to the usual keys, most keyboards today come with media keys to control audio and video: play/pause, volume, etc. We can control those too!

Here's a simple example that simulates pressing the *increase volume* button ten times to max it out:

```python
from adafruit_hid.consumer_control_code import ConsumerControlCode

for i in range(0, 10):
  consumer_control.send(ConsumerControlCode.VOLUME_INCREMENT)
```

You can find out lots more in the [`consumer_control` library docs](https://circuitpython.readthedocs.io/projects/hid/en/latest/api.html#adafruit-hid-consumer-control-consumercontrol).

***

### FULL CODE EXAMPLE

```python
import board
import digitalio
import time

import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

from adafruit_debouncer import Debouncer

# the extra library for the media keys
from adafruit_hid.consumer_control_code import ConsumerControlCode

url = 'https://www.youtube.com/watch?v=5G0zvL_VnGM'

pin = digitalio.DigitalInOut(board.D5)
pin.pull = digitalio.Pull.UP
button = Debouncer(pin)

time.sleep(1)
keyboard = Keyboard(usb_hid.devices)
keyboard_layout = KeyboardLayoutUS(keyboard)

def do_it():
  # open spotlight
  # press command then spacebar in one command!
  keyboard.press(Keycode.COMMAND, Keycode.SPACEBAR)
  keyboard.release_all()
  time.sleep(0.5)

  # type 'Firefox.app'
  keyboard_layout.write('Firefox.app')
  time.sleep(1)

  # return to open the browser
  keyboard.press(Keycode.RETURN)
  keyboard.release_all()
  time.sleep(1)

  # new tab, with two keys like above
  keyboard.press(Keycode.COMMAND, Keycode.T)
  keyboard.release_all()

  # type url and open it
  keyboard_layout.write(url)
  keyboard.press(Keycode.RETURN)
  keyboard.release_all()

  # very VERY DANGEROUS!
  # (you have been warned)
  # for i in range(0, 10):
  #   consumer_control.send(ConsumerControlCode.VOLUME_INCREMENT)

  # play the video
  time.sleep(2)
  keyboard.press(Keycode.K)
  keyboard.release_all()

while True:
  button.update()
  if button.fell:
    do_it()
```

***

### CHALLENGES  

1. Can you make a "save" button that sends `Command/control + S` to save whatever you're working on? What would you make this look like as a finished product?  
2. This process is like a derailed train once it gets going! Can you check the state of the button in the `do_it()` function and stop the process early if the button is released?  

