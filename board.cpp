#include "board.h"
#include <iostream>
#include <vector>

using namespace std;

void board(vector<char> deck[], vector<char> hidden[], int &numset, int numdeck) {
  // print the title of the gameboard
  cout << endl;
  cout << "       "
       << "GAMEBOARD" << endl;
  cout << " _______________________" << endl;
  // print the name of each column
  cout << "|  ";
  for (int i = 0; i < numdeck; i++) {
    cout << " " << i;
  }
  cout << " |"<<endl;
  cout <<"|                       |" <<endl;

  // count the length of the longest deck
  int max_length = 0;
  for (int col = 0; col < numdeck; col++) {
    int deck_length = hidden[col].size() + deck[col].size();
    if (deck_length > max_length) {
      max_length = deck_length;
    }
  }

  // print the gameboard
  for (int row = 0; row < max_length; row++) {
    // print the title of each row
    if (row<=9){
    cout << "|" << row << "  ";
    }
    else{
      cout << "|" << row << " ";
    }
    for (int col = 0; col < numdeck; col++) {
        // print dots representing the hidden cards
        if (hidden[col].size() >= (row + 1)) {
          cout << hidden[col][row] << " ";
        }
        // print cards that have been opened
        else {
          int deckrow = row - hidden[col].size();
          if (deck[col].size() >= (deckrow + 1)) {
            cout << deck[col][deckrow] << " ";
          } 
          else {
            cout << "  ";
          }
        }
      }
    cout << "|\n";
  }
  cout << " _______________________" << endl;
  cout << "\nNumber of cards in the card shuffler: " << numset << "*10."
       << endl;
  cout << endl;
}
