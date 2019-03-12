
/*
  SOUND OUTPUT
  Jeff Thompson | 2019 | jeffreythompson.org

  The Arduino is capable of primitive sound generation from
  its digital pins. The sound is basically the result of PWM
  output, very quickly turning the speaker on and off at a
  specified frequency. This is a square-wave, familiar from
  old-school videogames.

  (Why a resistor connected between the speaker and ground?
  The resistor helps prevent your speaker from drawing too
  much current and frying your Arduino. A tiny, cheap part
  but a lot of protection!)

  For higher-quality audio output, you'll need to use more
  than one digital output pin to create a Digital-to-Analog
  Converter (aka a DAC).

  CHALLENGES:
  + Can you connect multiple sensors, triggering different
    tones? For example, can you use several light-dependent
    resistors to trigger a tone if they get dark enough? (Or
    control them with a flashlight in the dark!)

*/


int sensorPin =  A0;    // potentiometer (or other analog sensor)
int speakerPin = 11;    // speaker for audio output (must be pwm)


void setup() {
  // nothing here :)
}


void loop() {

  // read the potentiometer
  int value = analogRead(sensorPin);

  // if the pot's value is 0, turn off the audio
  if (value == 0) {
    noTone(speakerPin);
  }

  // otherwise, use pot value to control frequency
  else {

    // convert the pot value to an audio frequency (200-2000Hz)
    int frequency = map(value, 0, 1023, 200, 2000);

    // play on the speaker pin for 20 milliseconds
    tone(speakerPin, frequency, 20);
  }
}

