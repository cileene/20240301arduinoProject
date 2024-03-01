#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  pinMode(12, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}