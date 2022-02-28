# PLOTTING AND SMOOTHING VALUES

We've seen ways to get analog sensor values into our boards, but there are two additional things that may help as we continue to explore this kind of sensor: plotting the values coming in and smoothing the (sometimes) jumpy analog signal.

***

### CONTENTS  

* [Basic setup](#basic-setup)  
* [Plotting values](#plotting-values)  
* [Smoothing](#smoothing)  
* [Full code example](#full-code-example)  
* [Challenges](#challenges)

### STUFF YOU'LL NEED  

* LDR  
* Resistor  
* Jumper wires  
* Feather board  
* USB cable  

***

### BASIC SETUP  
For this example, we'll use the LDR setup from the [last example](00-Potentiometer.md). Sensors that are less stable (like an LDR) will show the results more clearly than something like a potentiometer, but any analog sensors will work!

We'll use this code as our starting point:

```python
import board
import time
import analogio

ldr = analogio.AnalogIn(board.A5)

while True:
  value = ldr.value
  time.sleep(0.02)
```

***

### PLOTTING VALUES  
The `print()` command and the console are super useful tools, but sometimes just spitting out a ton of values doesn't give you enough information. It's easy to get lost in a steady stream of values, especially if the sensor isn't changing. Luckily, Mu Editor gives us another option: plotting!  

The plotting option gives us a graphical view of the incoming data. Everything is handled for us, all we need to do is make one small change to our code.

Instead of using `print()` with the value from the LDR:

```python
print(value)
```

We use syntax like this:
```python
print( (value,) )
```

> 🙋‍♀️ What's that weird formatting? Instead of sending a single value, we're wrapping up the value into something called a *tuple*. This is a structure for storing multiple values, noted with parentheses. The comma here is kind of a hack, forcing the `print()` command to see it as a tuple instead of a number in parentheses (for math purposes). By sending a tuple, Mu Editor is smart enough to send the data to the plotter!

Finally, we still want to add a small delay after plotting to prevent the USB connection from overloading with data:

```python
time.sleep(0.02)
```

That's it! Try it out, changing the values from the sensor. You should see the values changing live and the range auto-scaling to fit the data coming in.

***

### SMOOTHING  
Depending on what sensor you're using, you might notice the values aren't rock steady: they jump around a bit. That's because the sensors are physical things in the world! The LDR might get tiny fluctuations in brightness or the sensing material might have small variations or even be responding to ambient temperature. For some applications, we don't really care but there are times when this will be annoying. (A good example is controlling a motor, which can twitch if the sensor controlling it isn't even enough.)

There are a few different ways we can deal with this, but the easiest is to smooth the readings. We can do this by keeping track of some previous readings and averaging the result.

First, we need a way to keep track of the previous readings. The easiest way to do this is a list! Let's create a blank list at the top of our program:

```python
values = []
```

We'll also want to decide how many readings to store: the more we keep the more stable the result, but it will also be slower to respond to changes. I'd suggest experimenting here and see what works best for you. We'll make this as a global variable too, so we can easily tune it. We can also pre-populate our list with zeroes:

```python
num_values = 10
for i in range(0, num_values):
  values.append(0)
```

We can also do this using some fancy Python syntax, though the above works nicely too!

```python
values = [0] * num_values
```

Then, in our loop, we read the sensor, add its value to the list, and remove the oldest value:

```python
value = ldr.value     # read the sensor
values.append(value)  # add new value
values.pop(0)         # remove oldest (at index 0)
```

Finally, we average the list. There are lots of ways you could do this, but let's make a little function to make this easier:

```python
def average_list(l):
  return sum(l) / len(l)
```

We can then get a final value by sending our list of values into the function, then plot the result:

```python
mean = average_list(values)
print( (mean,) )
```

Try running it and watch the ways that it changes the result, and how changing the number of values stored alters the behavior.

***

### FULL CODE EXAMPLE  

```python
import board
import time
import analogio

ldr = analogio.AnalogIn(board.A5)

# list for smoothing values
num_values = 10
values = []

# fill list with 0s
for i in range(0, num_values):
  values.append(0)

# gives us the average of a list
# of values
def average_list(l):
  return sum(l) / len(l)

while True:
  value = ldr.value

  # add the new value to the list...
  values.append(value)

  # ...remove the oldest reading...
  values.pop(0)

  # ...and average the list to get
  # the smoothed value
  mean = average_list(values)

  # finally, send to Mu Editor for plotting
  print( (mean,) )

  # short delay, to avoid overloading
  # the USB connection with too much data
  time.sleep(0.02)
```

***

### CHALLENGES  

1. By adding additional numbers to the tuple, we can plot more than one value at the same time! Can you plot the averaged and original sensor reading together? Or can you add another sensor and print both?  
2. Sometimes we want to be able to change things in code, but often our projects are separate from a computer or we want to be able to tune stuff out in the world. Can you connect a potentiometer and use it to set the amount of smoothing?  

