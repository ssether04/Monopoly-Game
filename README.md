# Monopoly Game in C with Terminal GUI
This C program is a text-based implementation of the classic Monopoly board game with a graphical user interface (GUI) rendered in the terminal. It simulates the gameplay of Monopoly, allowing up to four players to participate and follow standard Monopoly rules.

## Features
- **Text-Based GUI:** The game provides a text-based graphical user interface (GUI) that renders the Monopoly board and displays player information in the terminal.
- **Up to Four Players:** You can play the game with up to four players, each represented by the first letter of the name entered.
- **Standard Monopoly Rules:** The game follows the traditional Monopoly rules, including property acquisition, rent payment, card drawing, and trading.
- **Property Management:** Players can buy properties, build houses/hotels, and mortgage properties based on their financial status.
- **Chance and Community Chest Cards:** The game includes Chance and Community Chest card decks, and players draw cards with various effects.
- **Jail:** Players can land in jail, attempt to get out of jail, or pay to leave jail.
- **Winning Conditions:** The game continues until only one player remains solvent, and they are declared the winner.

## Steps to run the application
- Make sure you have gcc compiler up and running
  - Windows: https://www.youtube.com/watch?v=2jpLG_XBVWI
  - MacOS: https://youtu.be/wY24ehH6mC0?si=9h5jZg4wHi977TMW
- **Compile the Program:** Compile the C program using a C compiler (e.g., gcc)
  ```bash
  gcc -o main main.c
  ```
- Make sure you have terminal on FULLSCREEN, or else the display will be messy
- **Run the Game:** To run the game, ensure you are running the main.exe file with the terminal on fullscreen mode, with no zoom i.e, the default settings of terminal
  ```bash
  main.exe
  ```
- After running main.exe, you will be greeted with a monopoly ascii art, use your trackpad to zoom out till the logo is in the center of the screen
- Then just follow the on screen instructions to start the game. Enjoy!

## Usage
- **Gameplay:** Follow the on-screen instructions to play the game. Input your choices using keyboard inputs (e.g., 'r' for rolling the dice, 'b' for buying property, etc.).
- **Player Turns:** Players take turns rolling dice, moving on the board, and performing actions such as buying properties, paying rent, or drawing cards.
- **Winning:** The game continues until a player has aquired all the properties or if the player is the only person standing who is not bankrupt

## Dependencies
This Monopoly game in C relies on standard C libraries for input/output and terminal manipulation. No external libraries or packages are required.

## Acknowledgments
This game is inspired by the classic Monopoly board game by Hasbro. Credits go to the original game designers for creating this iconic game.

## License
This project is open-source and available under the MIT License. You are free to use, modify, and distribute the code as per the license terms.

## Author
Varun Kamath

Enjoy playing Monopoly with your friends in the terminal!
