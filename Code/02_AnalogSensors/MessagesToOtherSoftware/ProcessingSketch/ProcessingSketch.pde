
import processing.serial.*;

/*
OSC: ARDUINO TO PROCESSING
 Jeff Thompson | 2019 | jeffreythompson.org
 
 A simple Processing sketch that receives a sensor reading
 from the Arduino and draws a circle whose diameter is driven
 by that sensor.
 
 */

int sensorReading = 0;    // variable from the potentiometer
Serial arduino;           // serial connection object from the Arduino


void setup() {
  size(400, 400);

  // get a list of all serial ports available
  String[] ports = Serial.list();
  printArray(ports);

  // select one to create a new serial connection
  // note our baud rate (9600) needs to match our Arduino sketch!
  arduino = new Serial(this, ports[6], 9600);
}


void draw() {
  
  // clear the background
  background(50);

  // if a new message is available...
  if (arduino.available() > 0) {
    
    // read it as a string until we get a newline character (\n)
    String message = arduino.readStringUntil('\n');

    // if the message is not null (empty)...
    if (message != null) {
      
      // convert the string into an integer
      // and convert to screen coords using map()
      sensorReading = Integer.parseInt(message.trim());      // trim() removes the newline character
      sensorReading = int( map(sensorReading, 0, 1023, 10, width-10) );
    }
  }

  // and draw a circle using the sensor reading
  // to change it's diameter!
  fill(255, 150, 0);
  noStroke();
  ellipse(width/2,height/2, sensorReading,sensorReading);
}
