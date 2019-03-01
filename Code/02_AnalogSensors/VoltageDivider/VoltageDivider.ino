
/*
  VOLTAGE DIVIDER
  Jeff Thompson | 2019 | jeffreythompson.org

  Our potentiometer makes reading analog values really
  easy. If you remember, the pot is really just a variable
  resistor, meaning the electricity coming into the pot is 
  reduced as we turn the knob – the electricity flowing back
  to the Arduino is what we're really reading!

  In fact, most analog circuits are variable resistors. In
  order to read them, though, we need a bit of additional
  circuitry called a "voltage divider," essentially just a
  second resistor.

  The voltage divider does two things:
  1. Allows us to get the maximum range from our sensor
  2. Ensures we never send the full 5V back into our Arduino!

  To calculate the value we need for the second resistor, we
  have to do some measuring and then a little math. Let's say
  we're choosing the resistor for a light sensor (aka a photo-
  cell).

  First, we measure the resistance of our sensor at it's two
  maximum points: in the dark and at full light. These values
  don't have to be 100% perfect, but close. To measure the
  resistance, we use a tool called a multimeter (there are some
  available for checkout from the VA&T Fab Lab).

    light level     resistance
    very bright     1k ohm
    very dark       10k ohm

  We then can guess that a good second resistor for our voltage
  divider would be about halfway between these two: about 4.5k
  ohms. Since that value isn't super common, we look for something
  close: 5.6k ohm should work.

  We can actually calculate the voltage the Arduino will see with
  this resistor using the ratio between the two resistors

    ratio = R2 / (R1 + R2)

  In our case...

    light = 5.6 / (1 + 5.6)  = 0.15
    dark  = 5.6 / (10 + 5.6) = 0.67

  If we multiply that by the 5V that the Arduino supplies, we
  can see the value coming into the analog pin...

    light = 5V * 0.15 = 0.76V
    dark  = 5V * 0.67 = 3.21V

  Not the full 5V range but good enough for most applications.
  Let's try wiring up a photocell with the 5.6k resistor to 
  control the brightness of an LED!

  More resources:
  + https://learn.sparkfun.com/tutorials/voltage-dividers/all
  + https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter

  CHALLENGES:
  1. Try reading the values from other sensors and record what
     you get. Use the system outlined above to calculate the
     resistor value needed to create a voltage divider. Test it!
  2. Some sensors are harder to test: for example humidity. Instead
     of traveling to the rainforest and desert just to record
     resistance values, you can look at the sensor's datasheet.
     Buried among lots of other technical information will be the
     resistance values for the sensor. Try looking up the datasheet
     for one of your sensors, calculate the voltage divider, and
     test your results!

*/

int sensorPin = A0;   // photocell
int ledPin =    9;    // LED on a PWM pin


void setup() {
  pinMode(ledPin, OUTPUT);
}


void loop() {

  // read the photocell
  int brightness = analogRead(sensorPin);

  // convert the input range (0-1023) to PWM range (0-255)
  brightness = map(brightness, 0,1023, 0,255);
  brightness = constrain(brightness, 0,255);

  // set the LED's brightness
  analogWrite(ledPin, brightness);
}




