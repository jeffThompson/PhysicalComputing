# MULTIPLE BUTTONS  

Just like LEDs, one button is cool but not as much fun as lots of buttons! There are lots of ways we could accomplish this, but in this example we'll leverage custom functions as a way to clean up and simplify repeated tasks in our code, then have an LED blink different patterns depending on which button is pressed.

***

### CONTENTS  

* [Wiring the buttons and LED](#wiring-the-buttons-and-led)  
* [Button variables](#button-variables)  
* [Reading the buttons](#reading-the-buttons)  
* [How many buttons can I have?](#how-many-buttons-can-i-have)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)  

### STUFF YOU'LL NEED  

* Two (or more) pushbuttons  
* One LED (or the internal one)  
* Jumper wires  
* Feather board  
* USB cable  

***

### WIRING THE BUTTONS AND LED  
To set up our board, we'll add a second button. This gets wired up just like the single button, with one end connected to ground and the other to a digital pin, in this case `D6`:

![](Images/MultipleButtons.png)

Add an LED from `D13` as well, just like in the image above. We can set up the LED in code too:

```python
led = digitalio.DigitalInOut(board.D13)
led.direction = digitalio.Direction.OUTPUT
```

***

### BUTTON VARIABLES  
With everything ready, can now create variables for our buttons. We could do this just like our previous example, creating a second set of variables for the new pin and button:

```python
pin1 = digitalio.DigitalInOut(board.D5)
pin1.pull = digitalio.Pull.UP 
button1 = Debouncer(pin1)

pin2 = digitalio.DigitalInOut(board.D6)
pin2.pull = digitalio.Pull.UP 
button2 = Debouncer(pin2)
```

This works, but as you can see, if we wanted more than two buttons it's going to get really messy! Looking closely at our code, we can see that all three lines needed to create a button are exactly the same, just with different input pins. This kind of generalization is a perfect opportunity for a function:

```python
def button_setup(pin):
  # create a button input
  # (with pullup resistor and debouncing)
  button = digitalio.DigitalInOut(pin)
  button.pull = digitalio.Pull.UP 
  return Debouncer(button)
```

This takes in the pin we want to use and sets it up for us, then sends back the button ready for debouncing. Let's add a button on pins `D5` and `D6` using our new function:  

```python
b1 = button_setup(board.D5)
b2 = button_setup(board.D6)
```

***

### READING THE BUTTONS  
Now we're ready to read our buttons! This works just like one button, but we'll need to call `update()` to get the state of each one:

```python
b1.update()
b2.update()
```

Now let's have the LED blink once if the first button is pressed, twice if the second one is pressed. Again, this is a great place to use a function: we can pass in the number of blinks!

```python
def blink(n, duration=0.2):
  # blinks an LED a specified number of times
  for i in range(0, n):
    led.value = True
    time.sleep(duration)
    led.value = False
    time.sleep(duration)
```

With this function done, we can trigger it when the button's state is `falling` (pressed):  

```python
if b1.fell:
  blink(1)
if b2.fell:
  blink(2)
```

You should see the LED blink once when the first button is pressed, twice when the second one is pressed!

***

### HOW MANY BUTTONS CAN I HAVE?  
At this point, you might be wondering how many buttons you can have in a project. A good question! At the most basic, we're limited by the number of digital pins on our board. This is one of the reasons we might choose a Feather over a cheaper board with fewer inputs or splurge on something like the Arduino Mega.

If we look at the *pinout* diagram (a drawing showing all the pins available to us and their names) for the Feather, we see some interesting things:

* Digital pins: the usual ones we've been using; noted as `D4–6` and `D9–13`  
* `RX/TX`: these are used for serial (USB) connection but can also be used as `D0` and `D1` respectively  
* `SCK/MOSI/MISO`: used for `SPI` communication but also can be used as `D25/D24/D23`  
* `SDA/SCL`: used for `I2C` communication (which we'll talk about later) but also can be used as `D21/D22`; **these do not have pullup resistors so you'll need to add them!⚡️**  
* Analog pins: these can also be used as digital inputs, using `D14–19` for `A0–5`

While theoreticaly these all will work, you may have to experiment.

**MUTLIPLEXING**  
But if we only have a limited number of digital pins, you might start thinking about devices like computer keyboards and wondering how they handle so many buttons! Does your keyboard have a digital pin for each key? While that would work, it's really not practical. Instead, you can use a variety of different methods to get around this. The most common of these is something called [*multiplexing*](https://en.wikipedia.org/wiki/Multiplexing). Essentially, a little chip sits between your buttons and Feather board. Inside is a switch that reads the state of one button, then the next, etc. It does this really fast, so quickly that we don't notice (unless you do e-sports or something).

The `CD74HC4067` multiplexing chip (what a mouthful!) is a great option and [Sparkfun has a nice breakout board](https://www.sparkfun.com/products/9056) to make using it even easier. This chip can be used for digital outputs too, so it's great for LEDs, and it can be chained together for even more buttons! It does require different code but is a super handy option for button-rich projects.

**OTHER OPTIONS**  
Of course there are other great and interesting solutions to this problem. You can run buttons together with resistors and read them as analog values. You can also make a keyboard matrix, where the buttons are connected in rows and columns. All of these require a lot of research and experimentation, though.

***

### FULL CODE EXAMPLE  
Copy/paste this code, save to your board:

```python
import board 
import digitalio
import time
from adafruit_debouncer import Debouncer

# LED setup
led = digitalio.DigitalInOut(board.D13)
led.direction = digitalio.Direction.OUTPUT

def button_setup(pin):
  # creates a button input
  # (with pullup resistor and debouncing)
  button = digitalio.DigitalInOut(pin)
  button.pull = digitalio.Pull.UP 
  return Debouncer(button)

# create the two buttons using our function
b1 = button_setup(board.D5)
b2 = button_setup(board.D6)

def blink(n, duration=0.2):
  # blinks an LED a specified number of times
  for i in range(0, n):
    led.value = True
    time.sleep(duration)
    led.value = False
    time.sleep(duration)

while True:
  # get the current button state
  b1.update()
  b2.update()
  
  # if falling (pressed), blink the LED
  if b1.fell:
    blink(1)
  if b2.fell:
    blink(2)
```

***

### CHALLENGES  

1. Can you add a third button and have it blink the LED three times?  
2. Could you add a second LED as well? Can you have one button blink one of the LEDs, the other button blink the other one?  
3. Can you make this into a simple adding machine? Using a global `total`, can you have one button add one to that number, the other two, then blink the result?  
4. This [super-helpful list of examples](https://github.com/todbot/circuitpython-tricks#set-up-and-debounce-a-list-of-pins) from Tod Kurt includes a method for debouncing multiple pins. Can you try implementing that here?  

