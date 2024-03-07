this is gonna become a working arduino project for the ruc workshop embedded programming spring 2024
*A simple handheld console that i would let my son Vincent play. Without any distractions but a bunch of abstractions to strengthen his imagination with a emphasis on experimentation as a “black box”.*

<img src="pictures/gameOfLife.png" width="200"><img src="pictures/pong.png" width="200"><img src="pictures/brickBreak.png" width="200"><img src="pictures/tetris.png" width="200">
- A programmable console for Vincent
    - Outputs
        - LED matrix instead of a screen
        - Simple speaker
        - Two leds (to show who’s turn it is)
    - Inputs
        - Rotary encoder
            - Like the PlayDate
        - d pad + a b buttons
            - GamBoy style
        - photocell
            - Think Boktai
        - Temp sensor
    - Game ideas
        - Tic tac toe
        - Battleship
        - Digital dice rolls
        - Adventure game
            - think the original zelda
    - OS
        - Simple C++
            - Define the inputs and outputs so it makes sense
                - Eg. UP, DOWN, LEFT, RIGHT
            - Define the “screen” so it’s easier to program to then a strip
            - Define a range of sounds
nick lee jerlung