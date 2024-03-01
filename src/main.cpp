#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6 // Pin where NeoPixels are connected


// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(16, PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

// put function declarations here:


// analog pin used to connect the potentiometer

// variable to read the value from the analog pin


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop()
{

  // if button on 10 is not high print button
  
  //delay(10);
  // print the time since program started
  // read the input on analog pin 0:

  // print out the value you read:



}

// put function definitions here:
/* int myFunction(int x, int y)
{
  return x + y;
} */