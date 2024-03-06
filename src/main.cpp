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
#define DELAYVAL 400 // Time (in milliseconds) to pause between pixels


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
  matrix.setBrightness(255);
  matrix.setTextColor(matrix.Color(50, 0, 0));
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
/*   for(int i=0; i<10; i++) {
    matrix.drawPixel(i, 0, matrix.Color(50, 0, 0));
    matrix.drawPixel(i, 1, matrix.Color(0, 50, 0));
    matrix.drawPixel(i, 2, matrix.Color(0, 0, 50));
    matrix.drawPixel(i, 3, matrix.Color(50, 0, 50));
    matrix.drawPixel(i, 4, matrix.Color(0, 50, 50));
    matrix.drawPixel(i, 5, matrix.Color(50, 0, 0));
    matrix.drawPixel(i, 6, matrix.Color(0, 50, 0));
    matrix.drawPixel(i, 7, matrix.Color(0, 0, 50));
    matrix.drawPixel(i, 8, matrix.Color(50, 0, 50));
    matrix.drawPixel(i, 9, matrix.Color(0, 50, 50));
    matrix.show();
    delay(DELAYVAL);
  } */
  // write the letter "V" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("V"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "I" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("I"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "N" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("N"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "C" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("C"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "E" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("E"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "N" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("N"));
  matrix.show();
  delay(DELAYVAL);
  // write the letter "T" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("T"));
  matrix.show();
  delay(DELAYVAL);
  // clear the screen
  matrix.fillScreen(0);
  matrix.show();
  delay(DELAYVAL);

  
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
