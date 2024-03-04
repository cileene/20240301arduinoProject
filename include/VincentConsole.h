// -------------------
// --- DEFINITIONS ---
// -------------------

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

// ---------------
// ---FUNCTIONS---
// ---------------

void initialSetup()
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