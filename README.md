
# Spider Solitaire 

Chen Weiqiao  (3035973581)
Khan Zunair   (3036060422)
Liu Shuyang   (3035973995)
Yang Qiwei    (3035854319)
Ye Xintong    (3035973593)

## Quick DEMO
[![Watch the video]](https://youtu.be/RsxnUybITv4)

## Description

Spider Solitaire is a captivating single-player card game that requires both strategy and skill. The objective of Spider Solitaire is to arrange the given decks of cards in sets of descending order, from King to Ace, within each of the game's ten columns. As you progress, the challenge intensifies with the introduction of more cards and fewer available moves. By strategically maneuvering the cards, players aim to clear the entire deck, and in doing so, win the game.

## Quick Start

1. Download the zip file, and unzip it.
2. Navigate to the directory of the unzipped folder usind cd commands.
3. Type `make main` in the terminal, compiling the game into an executable.
4. Type `./main` in the terminal to run the executable.
5. Follow the instructions shown on screen, and enjoy the game.

## Game Rules

1. The object of the game is to eliminate all the cards on the table by constructing columns of cards.
2. Each column should be arranged in descending order from K to A.
3. You can move cards between columns in the correct order (K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2, A) to organize the columns.
4. If you have an empty column, you can move any card or any consecutive deck to it.
5. You could deal a new row if there's no card to move.
6. But note - you can't deal new cards when you have any empty columns.
7. When the cards are arranged in the right order, they can be eliminated.
8. Eliminate all the cards to win the game!
   
## Features Implemented

+ Generation of random game sets or events.
  + Uses shuffle() to randomize the deck of cards to be drawn from.
+ Data structures for storing game data.
  + Uses vectors and arrays to store game data.
+ Dynamic memory management.
  + We dynamically manage the memory.
+ File input/output.
  + Uses multiple text files to save and load status of the game.
+ Program codes in multiple files.
  + Major functions are in separate files for ease of access / readability.
+ Proper indentation and naming styles.
  + We use proper names to each function and data, which clearly shows their functionality.
+ In-code documentation.
  + We use clear documentation in indicate the functionality of codes.

+ main.cpp
  + main program of the game.
+ newgame.cpp
  + generate a new game.
+ board.cpp
  + print board to users.
+ move.cpp
  + read moving instruction from users.
+ deal_hide.cpp
  + store data of unshown cards on the board.
+ deal.cpp
  + deal a row of new cards to the board.
+ collect.cpp
  + collect the straight if cards are in right order.
+ success.cpp
  + determine whether users win.

+ Header files
  + newgame.h
  + board.h
  + move.h
  + deal_hide.h
  + hide.h
  + collect.h
  + success.h

+ Makefile
  + complie files in to executable and link them.
  + clean files after operation.


-- COMP2113-ENGG1340_GP27 --
