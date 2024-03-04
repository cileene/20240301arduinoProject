// --- LIBRARIES ---

#include <Arduino.h>

// --- DEFINITIONS ---

// define the console output
#define CONSOLE Serial.println

// define the LED outputs
#define LED1ON digitalWrite(13, HIGH)
#define LED1OFF digitalWrite(13, LOW)
#define LED2ON digitalWrite(6, HIGH)
#define LED2OFF digitalWrite(6, LOW)
#define LED3ON digitalWrite(7, HIGH)
#define LED3OFF digitalWrite(7, LOW)
#define LED4ON digitalWrite(8, HIGH)
#define LED4OFF digitalWrite(8, LOW)

// define the button inputs if pressed
#define BTN1 (digitalRead(2) == HIGH)
#define BTN2 (digitalRead(3) == HIGH)
#define BTN3 (digitalRead(4) == HIGH)
#define BTN4 (digitalRead(5) == HIGH)

// define the potentiometers
#define POTL analogRead(A5)
#define POTR analogRead(A4)

// --- SETUP ---

void setup()
{
  // start the serial communication
  Serial.begin(9600);
  // set led pin as output
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  // set button pins as input
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

// --- LOOP ---

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
