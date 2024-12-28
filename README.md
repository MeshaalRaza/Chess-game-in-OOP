# Chess-game-in-OOP
# Chess Game

This is a simple chess game implemented in C++ that allows two players to play a game of chess on the console. The game features basic functionality, such as piece movement, turn-based gameplay, and display of the current state of the chessboard.

## Features
- Chessboard initialization with pieces in their starting positions.
- Players alternate turns to move pieces using standard chess notation (e.g., "e2 e4").
- The game displays the chessboard after each move, showing pieces represented by letters (e.g., 'WQ' for white queen, 'BK' for black king, etc.).
- The game supports basic move functionality but does not yet implement advanced rules like castling, en passant, or pawn promotion.

## How to Play
1. The game starts with the white player.
2. Players enter their moves in standard chess notation (e.g., `e2 e4` to move a piece from e2 to e4).
3. The game alternates turns between the two players until the program is stopped.
4. Invalid moves (such as moving an empty square or making an illegal move) will prompt the user to try again.

## Setup and Requirements
To run this program, you need a C++ compiler. You can use any C++ IDE or tool that supports C++11 or later.
Initial Board:
  a b c d e f g h
 +----------------
8| R N B Q K B N R | 8
7| P P P P P P P P | 7
6| . . . . . . . . | 6
5| . . . . . . . . | 5
4| . . . . . . . . | 4
3| . . . . . . . . | 3
2| P P P P P P P P | 2
1| R N B Q K B N R | 1
 +----------------
  a b c d e f g h
Enter move (e.g., e2 e4): e2 e4
Updated board after move:
  a b c d e f g h
 +----------------
8| R N B Q K B N R | 8
7| P P P P P P P P | 7
6| . . . . . . . . | 6
5| . . . . . . . . | 5
4| . . . . P . . . | 4
3| . . . . . . . . | 3
2| P P P P . P P P | 2
1| R N B Q K B N R | 1
 +----------------
  a b c d e f g h
Limitations:
The game currently does not include advanced chess rules such as:
En passant
Castling
Pawn promotion
The program only checks if a player is trying to move their own pieces. It doesn't validate specific legal moves for each piece.
Future Improvements:
Implement move validation (e.g., checking if a move is allowed for a specific piece).
Add support for special moves (castling, en passant, etc.).
Handle check and checkmate conditions.
Add a feature to undo or redo moves.
Support for saving and loading game states.
License:
This project is licensed under the MIT License - see the LICENSE file for details.



