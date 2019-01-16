
/*
  LED: WIHTOUT DELAY
  Jeff Thompson | 2018 | jeffreythompson.org

  One of the challenges we'll face over and over with the
  Arduino is multitasking. If we use delay() for anything,
  it stops the program entirely until that delay is finished.
  If we wanted to have a blinking LED that waited until a
  button was pressed, using delay() for the LED would stop
  our program for long stretches of time – the button press
  wouldn't feel very responsive at all!

  The trick is to keep track of the time manually and avoid
  using delay() altogether. The concept is a bit confusing
  but is worth trying to understand. We keep track of the
  time using the millis() command, which gives us the total
  number of milliseconds since the Arduino booted.

  Essentially:
  - store the current time
  - loop() over and over doing other stuff
  - once the interval has passed...
    - change the LED's state to HIGH/LOW
    - reset the timer
  - continue to loop again

  CHALLENGES:
  1. If we wanted to read a button while the LED was
     waiting to be changed, where would the code to
     read the button go?
  
*/


// how long to wait before toggling the LED (in milliseconds)
int interval = 500;

// keep track of the state of the LED so we can toggle it
int ledState = LOW;

// we also have to keep track of the last time the LED was
// toggled (which will be in milliseconds)
// "unsigned" means positive numbers only, "long" can hold
// larger values than an integer, which is good since the
// milliseconds can really add up!
unsigned long previousMillis = 0;


void setup() {

  // LED connected to digital pin 13 (either internal LED
  // or an external one connected between pin 13 and ground)
  pinMode(13, OUTPUT);
}


void loop() {

  // read the current time using the millis() command
  unsigned long millis = millis();

  // if the current time is greater than the previous time
  // plus the interval (ie enough time has elapsed) turn
  // the LED on or off
  if (currentMillis >= previousMillis + interval) {

    // toggle the LED's state and write that
    // value to the LED
    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
    digitalWrite(13, ledState);

    // reset the timer with the current time
    previousMillis = currentMillis;
  }
  
}

