// nick lee jerlung 2024

// -----------------
// --- LIBRARIES ---
// -----------------

#include <Arduino.h>
#include <VincentConsole.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 10
#define NUMPIXELS 100
#define DELAYVAL 1 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// -------------
// --- SETUP ---
// -------------

void setup()
{
  initialSetup();
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  CONSOLE("VINCENT ");
}

// ------------
// --- LOOP ---
// ------------

void loop()
{
  // print to the console when the buttons are pressed
  if (digitalRead(2) == HIGH)
  {
    CONSOLE("V");
  }
  if (digitalRead(3) == HIGH)
  {
    CONSOLE("I");
  }
  if (digitalRead(4) == HIGH)
  {
    CONSOLE("N");
  }
  if (digitalRead(5) == HIGH)
  {
    CONSOLE("C");
  }
  displayRGB();
}

unsigned long previousMillis = 0; 
const long interval = DELAYVAL; 
int state = 0;
int i = 0;

void displayRGB()
{
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    //pixels.clear(); // Set all pixel colors to 'off'

    switch(state) {
      case 0:
        pixels.setPixelColor(i, pixels.Color(5, 0, 0));
        break;
      case 1:
        pixels.setPixelColor(i, pixels.Color(0, 5, 0));
        break;
      case 2:
        pixels.setPixelColor(i, pixels.Color(0, 0, 5));
        break;
    }

    pixels.show();   
    i++;

    if(i >= NUMPIXELS) {
      i = 0;
      state++;
      if(state > 2) {
        state = 0;
      }
    }
  }
}
