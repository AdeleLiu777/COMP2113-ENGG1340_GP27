#include "deal.h"
#include <iostream>
#include <vector>
using namespace std;

void deal(vector<char> &left, vector<char> (&a)[10], int &numset) {

  // Draws cards from the left and deals them to each column of the deck
  for (int col = 0; col < 10; ++col) {
      // Get the cards at the top of the left and place them at the end of each deck 
      // columns on the game screen
      char card = left.back();
      left.pop_back();
      a[col].push_back(card);
  }
  numset--;
}
