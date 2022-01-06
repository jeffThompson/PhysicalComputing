
#include <TVout.h>     // import the library
#include <fontALL.h>   // and its built-in fonts

/*
  VIDEO GENERATION
  Jeff Thompson | 2019 | jeffreythompson.org

  While sound is (fairly) easy for the Arduino to generate, video
  is a whole other challenge, for the most part out of reach for
  our little board. But we can generate some rudimentary analog
  video in a way that is very similar to generating sound.

  The TVout library can draw basic shapes and text with pre-built
  fonts. You can also load custom images.

  WHAT ABOUT VGA? HDMI?
  Both VGA and HDMI are complex protocols are require way to fast
  a signal for your Arduino to keep up with. There are some "shields"
  (external boards that extend the functionality of your Arduino)
  that can handle this.

*/

TVout tv;   // instance of the TVout library


void setup() {
  
  // init the TVout library and select a font
  tv.begin(NTSC, 120,96);
  tv.select_font(font6x8);

  // display some text!
  tv.println("Hello world!");
  delay(2000);

  // show the various fonts
  tv.clear_screen();
  tv.println("I have a few fonts:");
  tv.select_font(font4x6);
  tv.println("4x6 font");
  tv.select_font(font6x8);
  tv.println("6x8 font");
  tv.select_font(font8x8);
  tv.println("8x8 font");
  tv.delay(4000);
}


void loop() {

  // clear the screen every frame
  tv.clear_screen();

  // circles
  // args: x, y, diameter, color (WHITE, BLACK, or INVERT)
  tv.draw_circle(50,50, 30, WHITE);
  tv.draw_circle(tv.hres()-50,tv.vres()-50, 30, WHITE);

  // rectangle
  // args: x, y, width, height, stroke color, fill color
  tv.draw_rect(50,50, tv.hres()-1000,tv.vres()-100, WHITE, INVERT);

  // lines
  // args: start x, start y, end x, end y, stroke color
  tv.draw_line(0,0, tv.hres(),tv.vres(), INVERT);
  tv.draw_line(0,tv.vres(), tv.hres(),0, INVERT);
}





