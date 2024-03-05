// nick lee jerlung 2024

// -----------------
// --- LIBRARIES ---
// -----------------

#include <Arduino.h>
#include <VincentConsole.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 10
#define NUMPIXELS 100
#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels

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
  CONSOLE("VINCENT CONSOLE");

}

// ------------
// --- LOOP ---
// ------------

void loop()
{
    pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(3, 0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
  // print the potentiometer values
  CONSOLE(POTL);
  // CONSOLE("POTR = " + String(POTR));
  // check if the button is pressed
  if BTN1
  {
    // turn on the LED
    LED1ON;
    tone(BUZZER_PIN, NOTE_A4);
    CONSOLE("BTN1 = LED1 ON");
  }
  else
  {
    // turn off the LED
    LED1OFF;
    noTone(BUZZER_PIN);
  }

  if BTN2
  {
    LED2ON;
    tone(BUZZER_PIN, NOTE_G5);
    CONSOLE("BTN2 = LED2 ON");
  }
  else
  {
    LED2OFF;
    noTone(BUZZER_PIN);
  }

  if BTN3
  {
    LED3ON;
    tone(BUZZER_PIN, NOTE_E5);
    CONSOLE("BTN3 = LED3 ON");
  }
  else
  {
    LED3OFF;
    noTone(BUZZER_PIN);
  }

  if BTN4
  {
    LED4ON;
    tone(BUZZER_PIN, NOTE_F5);
    CONSOLE("BTN4 = LED4 ON");
  }
  else
  {
    LED4OFF;
    noTone(BUZZER_PIN);
  }
}
