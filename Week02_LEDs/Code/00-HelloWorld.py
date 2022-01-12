'''
HELLO, WORLD!
Jeff Thompson | 2022 | jeffreythompson.org

Before we start turning on/off LEDs and wiring up circuits, let's see how we can upload code to our boards and cover some Python basics.

This is a multi-line comment, where we can put info about our program, etc.

BEFORE YOU START:
1. Connect your board to your computer via USB, it should show up as 'CIRCUITPY' just like a USB drive!
2. Inside you'll see three things, though we only need 'code.py' for now
3. Open the Mu Editor app and click the 'load' button, which opens the 'code.py' file locally on your computer
4. Click the 'Serial' button at the top
5. Lastly, copy/paste this code to the editor and click 'save' to upload it to your board

You're all set!

'''

'''
PRINT
The editor lets us not only edit and upload code, but also lets us get info back from our program, which is great for debugging. Click 'save' in the editor – after a few seconds you should see the text 'Hello, world!' show up in the console at the bottom
'''
print('Hello, world!')


'''
VARIABLES
In Python, variables are 'un-typed', meaning we don't have to tell Python if a value is a number or text or something else. To create a variable, all we need to do is...
'''
a = -5          # an integer (whole number)
b = 3.14        # a floating-point number (decimal)
c = 'Python'    # a string (text)

'''
Typically in Python, variables are written in all lowercase with underscores in between words. Other languages, like Javascript, usually write variables in camelCase instead. Both will work, but all the examples here will use the usual Python convention.
'''
a_longer_variable_name = 9.875

'''
Boolean (true/false) values are also possible but are always written with the first letter capitalized!
'''
i_like_donuts =    True
i_like_mushrooms = False

'''
Lastly, you may see the type 'None' from time to time. This is similar to 'null' in Java and 'undefined' in Javascript, meaning a variable with no value.
'''
friends = None   # :(


'''
MATH
Python uses the same mathematical symbols as other programming languages. Some more specialized operations (like square root below) may require importing the math library.

+   add
-   subtract
*   multiply
/   divide
()  parentheses help set the order of operations

'''
import math

width =  10
height = 12
hypotenuse = math.sqrt((width*width) + (height*height))
print('The hypotenuse is ' + str(hypotenuse) + ' inches')

# Note that we had to convert our computed value to a string to be able to print it with other text


'''
CONDITIONALS
Aka if/else statements. This is where Python can get a little tricky because we don't use curly brackets. Instead, Python requires you to indent code inside conditionals. You'll also notice we don't use parentheses!
'''
number_of_donuts = 2
number_of_people = 3
if number_of_donuts < number_of_people:
    print('There are not enough donuts!')
else:
    print('Whew, there are enough donuts')

# We can combine multiple conditionals using and/or as well
like_dogs = True
dog_nearby = True
if like_dogs and dog_nearby:
    print('Go say hi to the dog!')

am_hungry = True
cost_of_slice = 2 
my_money = 4.50
if am_hungry:
    if my_money > cost_of_slice:
        print('Pizza!')
    else:
        print('Not enough money for pizza... :(')

# And we can add else-if to our conditionals too – note that this is shortened in Python to 'elif'
current_time = 3
if current_time < 9:
    print('Not time for work yet')
elif current_time >= 9 and current_time < 5:
    print('Work time!')
else:
    print('Go home already')


'''
ITERATION
Like conditionals, iteration is indented and doesn't use curly brackets. First, we count from 0–9...
'''
for i in range(0, 10):
    print(i)

# Do the same thing, but count by twos...
for i in range(0, 10, 2):
    print(i)

# We can also go through lists easily...
vehicles = [ 'car', 'bus', 'truck', 'scooter', 'bike' ]
for vehicle in vehicles:
    print(vehicle)


'''
FUNCTIONS
Lastly, like in other languages, Python lets us create our own functions. These are indented just like conditionals and can include arguments, both required and optional.
'''
def add(a, b):
    result = a + b 
    return result
c = add(10, 50)
print(c)

# This one has an optional argument with a preset value
def punctuate(s1, s2, punct='.'):
    return s1 + ' ' + s2 + punct

print( punctuate('Lovely', 'day') )
print( punctuate('Wonderful', 'donuts', '!') )

'''
Of course, there's lots more Python can do and lots we haven't covered! But with these basics you should be able to do almost everything you need for this class, with a little Google/Stack Overflow searching from time to time.

If you find something we haven't covered that would be helpful, please let me know!
'''

