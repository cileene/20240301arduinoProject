// nick lee jerlung 2024

// -----------------
// --- LIBRARIES ---
// -----------------

#include <Arduino.h>
#include <VincentConsole.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

// Initialize the led matrixes
#define PIN 10

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 5, 2, 2, PIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                   NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG + NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS + NEO_TILE_PROGRESSIVE,
                                               NEO_GRB + NEO_KHZ800);

int DELAYVAL; // Time (in milliseconds) to pause between pixels
// Paddle positions (Y-coordinate, X is fixed)
int leftPaddleY = 4, rightPaddleY = 5;

// Ball position and direction
int ballX = 2, ballY = 2;
int ballDirX = 1, ballDirY = 1; // Ball movement direction

// Scores
int scoreLeft = 0, scoreRight = 0;

// -------------
// --- SETUP ---
// -------------

void setup()
{
  int noteDuration = 0;
  //int pauseBetweenNotes = noteDuration * 1.30;
  initialSetup();
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setTextColor(matrix.Color(50, 0, 0));
  // matrix.fillScreen(10);
  matrix.show();
  DELAYVAL = 400;
  // write the letter "V" to the full tiled matrix
  /* matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("V"));
  matrix.show();
  noteDuration = 125;
  tone(BUZZER_PIN, vincentJingle[0], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // delay(DELAYVAL);
  //  write the letter "I" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("I"));
  matrix.show();
  noteDuration = 125;
  tone(BUZZER_PIN, vincentJingle[1], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // write the letter "N" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("N"));
  matrix.show();
  noteDuration = 250;
  tone(BUZZER_PIN, vincentJingle[2], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // write the letter "C" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("C"));
  matrix.show();
  noteDuration = 125;
  tone(BUZZER_PIN, vincentJingle[3], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // write the letter "E" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("E"));
  matrix.show();
  noteDuration = 125;
  tone(BUZZER_PIN, vincentJingle[4], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // write the letter "N" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("N"));
  matrix.show();
  noteDuration = 250;
  tone(BUZZER_PIN, vincentJingle[5], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // write the letter "T" to the full tiled matrix
  matrix.fillScreen(0);
  matrix.setCursor(2, 2);
  matrix.print(F("T"));
  matrix.show();
  noteDuration = 500;
  tone(BUZZER_PIN, vincentJingle[6], noteDuration);
  delay(noteDuration * 1.30);
  noTone(BUZZER_PIN);
  // clear the screen
  matrix.fillScreen(0);
  matrix.show();
  delay(DELAYVAL); */
}

// ------------
// --- LOOP ---
// ------------
int gameSpeed = 200;
char lastWin;

void loop()
{
  //check the value of the potentiometer on analog pin 5
  int potValue = analogRead(A5);
  //if potvalue is more than 1010, mute all sounds
  if (potValue > 1010)
  {
    noTone(BUZZER_PIN);
  }

  
  matrix.setTextColor(matrix.Color(0, 0, 10));

  matrix.fillScreen(0); // Clear the matrix
  CONSOLE("left " + String(scoreLeft) + " right " + String(scoreRight));

  // Draw scores
  matrix.setCursor(0, 3);
  matrix.print(scoreLeft);
   matrix.setTextColor(matrix.Color(0, 5, 5));
  matrix.setCursor(4, 0);
  matrix.print(scoreRight);
  
  

  // Read buttons for paddle movement
  if (digitalRead(3) == HIGH)
  { // Move left paddle up
    leftPaddleY = max(leftPaddleY - 1, 0);
  }
  if (digitalRead(2) == HIGH)
  { // Move left paddle down
    leftPaddleY = min(leftPaddleY + 1, 9);
  }
  if (digitalRead(5) == HIGH)
  { // Move right paddle up
    rightPaddleY = max(rightPaddleY - 1, 0);
  }
  if (digitalRead(4) == HIGH)
  { // Move right paddle down
    rightPaddleY = min(rightPaddleY + 1, 9);
  }

  // Update and draw ball
  ballX += ballDirX;
  ballY += ballDirY;

  // Ball collision with top and bottom
  if (ballY <= 0 || ballY >= 9)
  {
    ballDirY = -ballDirY;
  }

  // Ball collision with paddles
  if (ballX <= 1 && (ballY == leftPaddleY || ballY == leftPaddleY - 1 || ballY == leftPaddleY + 1))
  { // Left paddle
    ballDirX = -ballDirX;
    // play tone
    tone(BUZZER_PIN, NOTE_A4, 35);
    delay(100);
    noTone(BUZZER_PIN);
  }
  else if (ballX >= 8 && (ballY == rightPaddleY || ballY == rightPaddleY - 1 || ballY == rightPaddleY + 1))
  { // Right paddle
    ballDirX = -ballDirX;
    // play tone
    tone(BUZZER_PIN, NOTE_C5, 35);
    delay(100);
    noTone(BUZZER_PIN);
  }

  // Scoring
  if (ballX < 0)
  { // Right player scores
    scoreRight++;
    ballX = 2;
    ballY = 2; // Reset ball
    gameSpeed -= 10; // Fix: Assign the result of the subtraction operation to the gameSpeed variable
  }
  else if (ballX > 9)
  { // Left player scores
    scoreLeft++;
    ballX = 4;
    ballY = 2; // Reset ball
    gameSpeed -= 10; // Fix: Assign the result of the subtraction operation to the gameSpeed variable
  }

  // Draw paddles and ball
  matrix.drawPixel(0, leftPaddleY, matrix.Color(75, 0, 0));      // Left paddle
  matrix.drawPixel(0, leftPaddleY + 1, matrix.Color(75, 0, 0));  // Left paddle
  matrix.drawPixel(0, leftPaddleY - 1, matrix.Color(75, 0, 0));  // Left paddle
  matrix.drawPixel(9, rightPaddleY, matrix.Color(75, 0, 0));     // Right paddle
  matrix.drawPixel(9, rightPaddleY + 1, matrix.Color(75, 0, 0)); // Right paddle
  matrix.drawPixel(9, rightPaddleY - 1, matrix.Color(75, 0, 0)); // Right paddle
  matrix.drawPixel(ballX, ballY, matrix.Color(40, 40, 40));       // Ball

  //reset the game when one of the players reaches 10 points
  if (scoreLeft == 10 || scoreRight == 10)
  {
    // reset the board
    leftPaddleY = 4;
    rightPaddleY = 5;
    ballX = 2;
    ballY = 2;
    scoreLeft = 0;
    scoreRight = 0;
    gameSpeed = 200;
  }

  matrix.show(); // Update the display
  delay(gameSpeed);    // Adjust for game speed
}