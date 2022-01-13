# HELLO, WORLD!

This week you'll learn to control various kinds LEDs with code. But first, let's get your Feather connected to the Mu Editor and go over some basics of [Python](https://www.python.org/), the langauge we'll be using to program our board. Python is a fantastic, flexible, and friendly language and is one of my faves.

This guide (and subsequent demos) assumes you've done at least some basic programming before. You should know a bit about variables, conditionals, and loops but it's ok if you've never used Python!

If you haven't already, be sure to [follow the steps for connecting and updating your board](00-SettingUpYourBoard.md) first.

***

### CONTENTS

* [Connect the board](#connect-the-board)  
* [Our first program](#out-first-program) 
* [Print](#print)  
* [Comments](#comments)  
* [Variables](#variables)  
* [Math](#math)  
* [Conditionals](#conditionals)  
* [Iteration](#iteration)  
* [Functions](#functions)  
* [Challenges](#challenges)  

### STUFF YOU'LL NEED  

* Feather board  
* USB cable  

***

### CONNECT THE BOARD
First, we need to get the board and Mu Editor talking to each other:

1. Connect your Feather board to your computer via USB, like before. It should show up as `CIRCUITPY`  
2. Open Mu Editor and click the `Load` button. Select the `code.py` file. You should now see a blank file where we can write some code  
3. Click the `Serial` button at the top of the editor. This lets us see messages and errors from the board, like the console in a web browser. We'll use this a lot for debugging parts of your program  

You'll use these steps every time you go to work on a project!

***

### OUR FIRST PROGRAM  
Let's verify everything is working and, in the process, write our first Circuit Python program. In the editor, copy/paste or type this line (you can delete anything that's already there):

```python
print('Hello, world!')
```

Click the `Save` button (`Ctrl+S` or `Cmd+S` will also work) to save your code to the board. You should immediately see some output in the console:

    Auto-reload is on. Simply save files over USB to run them or enter REPL to disable.
    code.py output:
    Hello, world!

    Code done running.

    Press any key to enter the REPL. Use CTRL-D to reload.

There's a bunch of stuff we don't have to worry about yet, but the important thing is that it displays the text we wrote using the `print()` command. Nice!

***

### PRINT  
We've already covered this command a bit! `print()` is super helpful for debugging, especially when working with a board like the Feather that has no display of its own.

Any values inside `print()` will show up in the console. This includes text, variables, lists, etc. If you haven't used `print()` or similar commands much in the past, now's a great time to start using it more!

***

### COMMENTS  
Comments are code that isn't run, but instead is there to offer info to people reading it. Adding comments is a great habit to get into: not only is it the professional thing to do (and therefore looks great when sharing your code with potential employers) it also leaves notes for yourself when you come back later and try to remember what the heck you were doing! In Python, we can create two kinds of comments.

**SINGLE LINE**  
Any text after a `#` symbol is a comment. These can be on a line of their own...

```python
# turn the LED on
```

...or after a line of code:

```python
a = 2 * 3   # multiply two numbers together
```

**MULTIPLE LINE**  
For larger blocks of text, you can create multi-line comments. These start and end with three quote-marks, either single or double will work the same:

```python
'''
This comment is on multiple lines.
It starts and ends with three single quote-marks.
'''

"""
This 
works 
too!
:)
"""
```

***

### VARIABLES  
In Python, variables are ["un-typed,"](https://fosterv222.medium.com/coding-languages-typed-vs-untyped-d29c7e0b3713) meaning we don't have to tell Python if a value is a number or text or something else, and variables can change type. To create a variable, all we need to do is give it a name and an initial value!

```python
a = -5          # an integer (whole number)
b = 3.14        # a floating-point number (decimal)
c = 'Python'    # a string (text)
```

You'll also notice that we don't need semicolons at the end of lines of code in Python!

Typically in Python, variables are written in all lowercase with underscores in between words. In other languages, like Javascript, we usually write variables in `camelCase` instead. Both will work, but all the examples here will use the usual Python convention:


```python
a_longer_variable_name = 9.875
```

There are a few specific variable types that are a bit different than other languages...

**BOOLEAN**  
A variable can be boolean (true/false) too but are always written with the first letter capitalized!

```python
i_like_donuts =    True
i_like_mushrooms = False
```

**NONE**  
You may see a variable with a value of `None` from time to time. This is similar to `null` in Java and `undefined` in Javascript, meaning a variable with no value.

```python
friends = None   # :(
```

**LISTS**  
List handling is one of the best parts of Python. Lists are noted with square brackets:

```python
pets = [ 'June', 'Kahn' ]
```

We can get the length of a list using `len()`:

```python
print(len(pets))
```

Adding an item is easy:

```python
pets.append('Manchego')
```

There's a ton more we can do with lists in Python, but for now we'll leave it there! There are lots of great resources online if you want more.

***

### MATH  
Python uses the same mathematical symbols as other programming languages.

    +   add
    -   subtract
    *   multiply
    /   divide
    ()  parentheses help set the order of operations

Some more specialized operations (like square root) may require importing the math library, which we do at the top of our code.

```python
import math
root = math.sqrt(9)
```

You can find a [full list of math operations in the Circuit Python documentation](https://circuitpython.readthedocs.io/en/latest/shared-bindings/math/index.html).

**I'M GETTING AN ERROR TRYING TO PRINT VARIABLES!**  
Printing a single value should always work, but if you try to combine strings and other types...

```python
radius = 30
print('The radius is: ' + radius)
```

...you may get an error: `TypeError: can only concatenate str (not "int") to str`

To solve this, we can do two things. Instead of using `+`, we can separate values with a comma instead:

```python
radius = 30
print('The radius is:', radius)
```

Or we can convert non-string (numbers, lists, etc) values into text using the `str()` command:

```python
radius = 30
print('The radius is: ' + str(radius))
```

***

### CONDITIONALS  
Aka `if/else` statements. This is where switching to Python can get a little tricky because we don't use curly brackets like most langauges. Instead, Python requires you to indent code to tell it what's part of your if-statement. You'll also notice we don't use parentheses either!

```python
number_of_donuts = 2
number_of_people = 3
if number_of_donuts < number_of_people:
  print('There are not enough donuts!')
else:
  print('Whew, there are enough donuts')
```

We can combine multiple conditionals using `and`...

```python
like_dogs =  True
dog_nearby = True
if like_dogs and dog_nearby:
  print('Go say hi to the dog!')
```

...and `or` too:

```python
am_hungry =     True
cost_of_slice = 2 
my_money =      4.50

if am_hungry:
  if my_money > cost_of_slice:
    print('Pizza!')
  else:
    print('Not enough money for pizza...')
```

If we need to check more than two combinations, we can add one or more `else-if` statements to our conditionals too. Note that this is shortened in Python to `elif`:

```python
current_time = 3
if current_time < 9:
  print('Not time for work yet')
elif current_time >= 9 and current_time < 5:
  print('Work time!')
else:
  print('Go home already')
```

***

### ITERATION  
Like conditionals, iteration is indented and doesn't use curly brackets. First, let's count from `0–9`:

```python
for i in range(0, 10):
  print(i)
```

The same thing, but counting by twos:

```python
# third value is the step size
for i in range(0, 10, 2):
  print(i)
```

We can go backwards too!

```python
# -1 means go backwards by 1
for i in range(10, 0, -1):
  print(i)
```

Lastly, Python also makes going through lists easy:

```python
vehicles = [ 'car', 'bus', 'truck', 'scooter', 'bike' ]
for vehicle in vehicles:
  print(vehicle)
```

***

### FUNCTIONS  
Lastly, Python lets us create our own functions. These are indented just like conditionals and loops, and can include arguments, both required and optional. **Note that we have to create our function above the code where we use it, otherwise we'll get an error that the function can't be found!**

Let's make a simple function that adds two numbers:

```python
def add(a, b):
  result = a + b 
  return result
```

Then we can use it!

```python
c = add(10, 50)
print(c)
```

This function has an optional argument with a preset value. If we don't include anything for that argument, Python will use the default that's listed.

```python
def punctuate(a, b, punct='.'):
  return a + ' ' + b + punct

print( punctuate('Lovely', 'day') )
print( punctuate('Wonderful', 'donuts', '!') )
```

This will add the default punctuation (a period) unless we specify a different punctuation mark to use, like in the second example.

***

### CHALLENGES  

1. Try changing the text inside the `print()` command. Save it and watch the console again to see the output  
2. Can you write a simple Python program that outputs various text to the console? What creative things can you do with such a simple interaface?  

***

Of course, there's lots more Python can do and lots we haven't covered! But with these basics you should be able to do almost everything you need for this class, with a little Google/Stack Overflow searching from ~time to time~ every week.

If you find something we haven't covered that would be helpful, please let me know!

