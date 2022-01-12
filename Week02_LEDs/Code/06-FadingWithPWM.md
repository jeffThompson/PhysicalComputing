# FADING WITH PULSE-WIDTH MODULATION

Blinking an LED is cool, but what if we want to vary its brightness? As the name implies, a "digital" pin can only be turned on or off, we can't set them to be partially on. Luckily, some very smart people figured out that if we flash the LED on/off really quickly, we can trick our eye into thinking that the brightness has been dimmed – pretty cool!

This is called [pulse-width modulation](https://en.wikipedia.org/wiki/Pulse-width_modulation) (PWM) and the Feather board allows us to use it on all the digital pins. More on how PWM works below.

***

### CONTENTS  
* [Basic PWM output](#basic-pwm-output)  
* [More intuitive values](#more-intuitive-values)  
* [Full code example](#full-code-example)  
* [What if my LED looks jumpy?](#what-if-my-led-looks-jumpy)  
* [Challenges](#challenges)  

### MATERIALS  
* Feather board  
* USB cable  

***

### BASIC PWM OUTPUT  
We'll be using the built-in LED for this example, so we can jump right into the code and change its brightness!

First, we import the `board` and `time` libraries, plus a special one for PWM control:

```python
import board
import time
import pwmio
```

Then we set up our pin for PWM. Don't worry about `frequency`, we can just leave that as the default. We'll change `duty_cycle` later:

```python
led = pwmio.PWMOut(
    board.LED, 
    frequency=5000, 
    duty_cycle=0
)
```

Now let's set the brightness! We do this by changing the "duty cycle" value for the LED pin:

```python
led.duty_cycle = 65535
```

[Duty cycle](https://en.wikipedia.org/wiki/Duty_cycle) refers to how much of the time the LED is on and how much it is off. The pin can receive values between `0` (completely off) and `65535` (max brightness), and any value in between.

**WHAT A WEIRD NUMBER, WHY 65535?**  
TLDR: that's the max brightness allowed but it's really confusing. We'll fix that in the next step, so skip ahead or read below for more details...

Computers use binary values: true or false, zero or one. We call this "base 2," which works just like the decimal (base 10) numbers we're used to, but instead of using the digits `0–9`, it only uses `0` and `1`. The maximum value allowed in a computer system varies depending on its internal architecture: many microcontrollers (like Arduino) may be limited to only 8-bit values:

    2^8 = a maximum value of 255

But the PWM pins on our Feather board can receive 16-bit values:

    2^16 = a maximum value of 65535!

That's a lot higher, meaning we get way more resolution to the dimming of our LED! But, if you're like me, that value is super confusing, so we'll fix that in the next step...

***

### MORE INTUITIVE VALUES  
Unless you do a lot of this kind of thing, thinking in 16-bit values is not at all intuitive. Luckily, programming allows us to make this work better for us.

What we want to do is make a new, easier to remember range of values and convert them into what our Feather board expects. Some languages, like `p5.js` and `Processing`, have a built-in function that does this called `map()`. Python doesn't have such a function, but we can build one ourselves! (Or, more accurately, we can do some Google searching and modify an example for our use.)

```python
# via: https://stackoverflow.com/a/929107/1167783
def scale_pwm(n, in_min, in_max, out_min=0, out_max=65535):
    val = (((n - in_min) * (out_max - out_min)) / (in_max - in_min)) + out_min
    return int(val)
```

The math here is kind of funky so we won't get into details, but essentially we give the function:

* An input value to be scaled  
* The lowest and highest possible values in the range we want to use  
* And the lowest/highest possible values from the range the Feather is expecting (these are presets in the function, so we don't have to specify them)  
* The results are converted from a float-point (decimal) number to an integer (whole number), since that's what's required for PWM output  

To me, a PWM range of `0–100` seems pretty good. We can use our new function like this:

```python
brightness = 50
new_brightness = scale_pwm(brightness, 0,100)
```

This takes the value `50` and converts it to `32767.5`, or half of `65535`, then converts it to an integer value of `32768`. Let's use that to fade the LED in and out.

```python
while True:
  # fade in...
  for i in range(0, 100):
    led.duty_cycle = scale_pwm(i, 0,100)
    time.sleep(0.005)

  # ...then fade out
  for i in range(100, 0, -1):
    led.duty_cycle = scale_pwm(i, 0,100)
    time.sleep(0.005)
```

***

### FULL CODE EXAMPLE  
Putting everything together, we create the PWM pin, add our custom-made function, then fade the LED over and over:

```python
import board
import time
import pwmio

led = pwmio.PWMOut(
    board.LED, 
    frequency=5000, 
    duty_cycle=0
)

# via: https://stackoverflow.com/a/929107/1167783
def scale_pwm(n, in_min, in_max, out_min=0, out_max=65535):
    val = (((n - in_min) * (out_max - out_min)) / (in_max - in_min)) + out_min
    return int(val)

while True:
  # fade in...
  for i in range(0, 100):
    led.duty_cycle = scale_pwm(i, 0,100)
    time.sleep(0.02)

  # ...then fade out
  for i in range(100, 0, -1):
    led.duty_cycle = scale_pwm(i, 0,100)
    time.sleep(0.02)
```

***

### WHAT IF MY LED LOOKS JUMPY?  
If you want really slow, smooth fading, you might find that our example looks a bit jumpy. That's because we're reducing the resolution of the pin three orders of magnitude! For most purposes you probably won't notice, but if you do, we can just change the input range for our `scale_pwm()` function.

Instead of:  
```python
for i in range(0, 100):
    led.duty_cycle = scale_pwm(i, 0,100)
    time.sleep(0.02)
```

Try:  
```python
for i in range(0, 1000):
    led.duty_cycle = scale_pwm(i, 0,1000)
    time.sleep(0.002)
```

Should be much smoother!

***

### CHALLENGES  
1. Can you connect an external LED and have it fade? What about two LEDS?  
2. Python's `random` library has a bunch of options for creating random numbers. Can you use it to set the LED to a random brightness once a second? (Hint: import the library and use `random.randint(0, 65535)`)  

