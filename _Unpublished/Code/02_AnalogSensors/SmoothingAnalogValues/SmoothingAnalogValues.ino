/*
  SMOOTHING ANALOG VALUES (and Serial Plotter)
  Jeff Thompson | 2019 | jeffreythompson.org

  The real world is messy: sensors never return smooth, perfect
  values. They bounce around, are susceptible to noise from your
  wire, the input pins on the Arduino, the materials of the
  sensor, even things like radio interference and solar wind!

  To avoid this, we can average the incoming data, essentially
  smoothing out the values coming in. This is a trade-off though:
  the more smoothing we apply, the slower and less fine-grained
  our input becomes. If you need super-fast input for a game
  controller, you'll want to dial back the smoothing; if you want
  to control a motor with an analog sensor, you probably want
  more smoothing to avoid jerky motion.

  To see this more clearly, we can view the values from our sensor
  in the Serial Plotter, which graphically displays the values!

*/


// to smooth our input, we'll store a set of previous readings and
// average them – how many values we store will change the overall
// smoothness of the value we get
const int numReadings = 20;   // "const" is required so we can use it to create the array

// to store the values, we'll create an array (a list) of values
// and replace the oldest every time we read the sensor
int readings[numReadings];    // square brackets denotes an array

int readIndex = 0;            // curent array index we're reading the sensor into
int total =     0;            // the running total of our previous readings
int average =   0;            // the average of the previous readings

int sensorPin = A0;           // a sensor (pot or any other)


void setup() {
  Serial.begin(9600);

  // initialize all readings in our array to 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}


void loop() {

  // subtract the last reading from the total
  total = total - readings[readIndex];

  // read the sensor
  int value = analogRead(sensorPin);

  // print to the Serial Monitor and Plotter
  Serial.print(value);  // print() to keep both values on the same line
  Serial.print(" ");    // a space, required for the Plotter to know
                        // there are two values to display

  // add the value to the array and the total
  readings[readIndex] = value;
  total += value;

  // calculate the average and print to the Serial Monitor/Plotter
  average = total / numReadings;
  Serial.println(average);

  // update the index to the next position in the array
  // if we're at the end, go back to the start (position 0)
  readIndex += 1;
  if (readIndex == numReadings) {
    readIndex = 0;
  }

  // lastly, add a short delay between readings for stability
  delay(1);
}







