// nick lee jerlung 2024

// -----------------
// --- LIBRARIES ---
// -----------------

#include <Arduino.h>
#include <VincentConsole.h>



// -------------
// --- SETUP ---
// -------------

void setup()
{
  initialSetup();

}

// ------------
// --- LOOP ---
// ------------

void loop()
{
  // print the potentiometer values
  CONSOLE(POTL);
  // CONSOLE("POTR = " + String(POTR));
  // check if the button is pressed
  if BTN1
  {
    // turn on the LED
    LED1ON;
    CONSOLE("BTN1 = LED1 ON");
  }
  else
  {
    // turn off the LED
    LED1OFF;
  }

  if BTN2
  {
    LED2ON;
    CONSOLE("BTN2 = LED2 ON");
  }
  else
  {
    LED2OFF;
  }

  if BTN3
  {
    LED3ON;
    CONSOLE("BTN3 = LED3 ON");
  }
  else
  {
    LED3OFF;
  }

  if BTN4
  {
    LED4ON;
    CONSOLE("BTN4 = LED4 ON");
  }
  else
  {
    LED4OFF;
  }
}
