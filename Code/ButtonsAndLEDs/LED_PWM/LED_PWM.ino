
/*
  LED: PWM
  Jeff Thompson | 2018 | jeffreythompson.org

  Just turning an LED on and off is cool, but what
  about being able to control the brightness? Reducing
  the voltage to the LED would accomplish that, but
  our Arduino can only send out 5V. But there's a neat
  trick we can use called Pulse Width Modulation (PWM).

  By turning the LED on and off really quickly, our
  eyes see the LED as being dimmed. Changing the rate
  of pulsing will make the LED seem brighter or
  dimmer – pretty cool!

  PWM expects values between 255 (max brightness, same
  as HIGH when using digitalWrite()) and 0 (min
  brightness, same as LOW).

  We'll use this technique later to control the speed
  of a motor too :)

  CHALLENGES:
  1. Can you use the for-loop to make the LED get
     slowly dimmer, then brighter, then dimmer again?
  2. Can you make the LED display random brightness,
     changing every 100 milliseconds? (Hint: use the
     random() function)

*/

void setup() {
  pinMode(13, OUTPUT);
}


void loop() {

  // turn on the LED at different brightnesses
  analogWrite(13, 255);   // full strength
  delay(100);
  analogWrite(13, 200);   // ...a little dimmer
  delay(100);
  analogWrite(13, 150);   // ...halfway
  delay(100);
  analogWrite(13, 100);   // ...dimmer still
  delay(100);
  analogWrite(13, 50);    // ...really dim
  delay(100);

  // turn off the LED
  // (could use analogWrite(13, 0) too)
  digitalWrite(13, LOW);
  delay(100);

  // fancier version
  // the version above works ok, but it doesn't
  // really let us do a smooth fade without tons
  // of redundant code – a for-loop would work
  // much better!
  // for (int i=255; i<=0; i-=1) {
  //   analogWrite(13, i);
  //   delay(5);
  // }
}

