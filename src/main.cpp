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
int ballX = 4, ballY = 4;
int ballDirX = 1, ballDirY = 1; // Ball movement direction

// Scores
int scoreLeft = 0, scoreRight = 0;

// -------------
// --- SETUP ---
// -------------

void setup()
{
  // start the serial communication
  Serial.begin(9600);
  // print to the console
  CONSOLE("VINCENT ");
  
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
  matrix.begin();
  matrix.setBrightness(255);
  matrix.setTextColor(matrix.Color(50, 0, 0));
  // matrix.fillScreen(10);
  matrix.show();
   DELAYVAL = 400;
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
}

// ------------
// --- LOOP ---
// ------------

void loop() {
  matrix.fillScreen(0); // Clear the matrix
  
  // Read buttons for paddle movement
  if (digitalRead(2) == HIGH) { // Move left paddle up
    leftPaddleY = max(leftPaddleY - 1, 0);
  }
  if (digitalRead(3) == HIGH) { // Move left paddle down
    leftPaddleY = min(leftPaddleY + 1, 9);
  }
  if (digitalRead(4) == HIGH) { // Move right paddle up
    rightPaddleY = max(rightPaddleY - 1, 0);
  }
  if (digitalRead(5) == HIGH) { // Move right paddle down
    rightPaddleY = min(rightPaddleY + 1, 9);
  }

  // Update and draw ball
  ballX += ballDirX;
  ballY += ballDirY;

  // Ball collision with top and bottom
  if (ballY <= 0 || ballY >= 9) {
    ballDirY = -ballDirY;
  }

  // Ball collision with paddles
  if (ballX <= 0 && ballY == leftPaddleY or leftPaddleY-1 or leftPaddleY+1) { // Left paddle
    ballDirX = -ballDirX;
  } else if (ballX >= 9 && ballY == rightPaddleY or rightPaddleY-1 or rightPaddleY+1) { // Right paddle
    ballDirX = -ballDirX;
  }

  // Scoring
  if (ballX < 0) { // Right player scores
    scoreRight++;
    ballX = 2; ballY = 2; // Reset ball
  } else if (ballX > 4) { // Left player scores
    scoreLeft++;
    ballX = 2; ballY = 2; // Reset ball
  }

  // Draw paddles and ball
  matrix.drawPixel(0, leftPaddleY, matrix.Color(50, 0, 0)); // Left paddle
  matrix.drawPixel(0, leftPaddleY+1, matrix.Color(50, 0, 0)); // Left paddle
  matrix.drawPixel(0, leftPaddleY-1, matrix.Color(50, 0, 0)); // Left paddle
  matrix.drawPixel(9, rightPaddleY, matrix.Color(50, 0, 0)); // Right paddle
  matrix.drawPixel(9, rightPaddleY+1, matrix.Color(50, 0, 0)); // Right paddle
  matrix.drawPixel(9, rightPaddleY-1, matrix.Color(50, 0, 0)); // Right paddle
  matrix.drawPixel(ballX, ballY, matrix.Color(30, 30, 0)); // Ball

  matrix.show(); // Update the display
  delay(200); // Adjust for game speed
}