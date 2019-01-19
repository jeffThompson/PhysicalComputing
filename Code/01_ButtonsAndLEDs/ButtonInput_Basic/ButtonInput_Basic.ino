
/*
  BUTTON INPUT: BASIC
  Jeff Thompson | 2018 | jeffreythompson.org

  So far we've seen ways to control a simple LED using the
  Arduino and a bit of code. Cool, but what if we want to
  get some kind of reading into the computer. A button is a
  super simple *digital* sensor, giving us a value of HIGH
  or LOW depending on if it is pressed or not.

  Buttons come in many different forms: the small ones in your
  parts kit, huge ones on arcade games, little ones for 
  controlling the volume of your phone... they're everywhere.

  CIRCUIT:
  There are several ways to hook up buttons to your
  Arduino, but the one we'll use is the easiest.

  1. Plug your button into your breadboard, straddling
     the center gap
  2. Attach a jumper wire from any leg on the button to
     digital pin 2 on the Arduino
  3. Attach a jumper wire from the opposite leg to ground
     on the Arduino

  That's it! See the schematic diagram in the sketch folder
  for details.

  CHALLENGES:
  1. Can you wire up and write code to connect two buttons 
     and two LEDs?

*/

void setup() {

  // set the mode for our button pin (digital pin 2)
  // as INPUT_PULLUP
  pinMode(2, INPUT_PULLUP);

  // why INPUT_PULLUP?
  // there is a built-in INPUT mode that you may see in other
  // examples, but we can't use it without some additional parts
  // INPUT_PULLUP uses a built-in resistor on the board to
  // ensure we don't send the full 5V from the Arduino back into
  // itself, which will likely cause it to stop working and could
  // do damage to your computer!
  // INPUT_PULLUP is nice because it means we don't need any
  // extra parts or wires, which is especially great when doing
  // more complex projects or production circuits
  
  // set the LED pin to output
  pinMode(13, OUTPUT);
}


void loop() {

  // read the button's state into a variable
  int state = digitalRead(2);

  // if the button's state is HIGH turn on the LED
  if (state == HIGH) {
    digitalWrite(13, HIGH);
  }

  // if LOW, turn off the LED
  else {
    digitalWrite(13, LOW);
  }

  // notice something weird?
  // with the INPUT_PULLUP the button input is the opposite
  // of what we'd expect: LOW means the button is pressed and
  // HIGH means it isn't
  // try changing the code above so the light comes on when
  // the button is pressed (LOW)
}

