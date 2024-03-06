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
//#define NUMPIXELS 100
#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 5, 2, 2, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG + NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS + NEO_TILE_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


// -------------
// --- SETUP ---
// -------------

void setup()
{
  initialSetup();
  matrix.begin();
  matrix.setBrightness(50);
  //matrix.fillScreen(10);
  matrix.show();
}

// ------------
// --- LOOP ---
// ------------

void loop()
{
  // print to the console when the buttons are pressed
  if (digitalRead(2) == HIGH)
  {
    CONSOLE("btn1");
  }
  if (digitalRead(3) == HIGH)
  {
    CONSOLE("btn2");
  }
  if (digitalRead(4) == HIGH)
  {
    CONSOLE("btn3");
  }
  if (digitalRead(5) == HIGH)
  {
    CONSOLE("btn4");
  }
 // run through each of the pixels on the full tiled matrix
  for(int i=0; i<10; i++) {
    matrix.drawPixel(i, i, matrix.Color(50, 0, 0));
    matrix.drawPixel(i, i, matrix.Color(0, 50, 0));
    matrix.drawPixel(i, i, matrix.Color(0, 0, 50));
    matrix.drawPixel(i, i, matrix.Color(50, 0, 50));
    matrix.drawPixel(i, i, matrix.Color(0, 50, 50));
    matrix.show();
    delay(DELAYVAL);
  }
  // animate a face on the full tiled matrix


}

/* unsigned long previousMillis = 0;
const long interval = DELAYVAL;
int state = 0;
int i = 0;

void displayRGB()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    // pixels.clear(); // Set all pixel colors to 'off'

    switch (state)
    {
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

    if (i >= NUMPIXELS)
    {
      i = 0;
      state++;
      if (state > 2)
      {
        state = 0;
      }
    }
  }
} */
