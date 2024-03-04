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
