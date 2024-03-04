#include <Arduino.h>

// define the LED outputs
#define LED1ON digitalWrite(13, HIGH)
#define LED1OFF digitalWrite(13, LOW)
#define LED2ON digitalWrite(6, HIGH)
#define LED2OFF digitalWrite(6, LOW)
#define LED3ON digitalWrite(7, HIGH)
#define LED3OFF digitalWrite(7, LOW)
#define LED4ON digitalWrite(8, HIGH)
#define LED4OFF digitalWrite(8, LOW)



void setup()
{

  Serial.begin(9600);
  //set led pin as output
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{

  // blink pin d 13
LED1ON;
  delay(1000);
  Serial.println("LED1 ON");
LED1OFF;
  delay(1000);
  Serial.println("LED1 OFF");
LED2ON;
  delay(1000);
  Serial.println("LED2 ON");
LED2OFF;
  delay(1000);
  Serial.println("LED2 OFF");
LED3ON;
  delay(1000);
  Serial.println("LED3 ON");
LED3OFF;
  delay(1000);
  Serial.println("LED3 OFF");
LED4ON;
  delay(1000);
  Serial.println("LED4 ON");
LED4OFF;
  delay(1000);
  Serial.println("LED4 OFF");
}
