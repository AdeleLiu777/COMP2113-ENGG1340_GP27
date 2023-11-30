#include "deal_hide.h"
#include <iostream>
#include <vector>

using namespace std;

void deal_hide(vector<char>& left, vector<char>& source_pile, vector<char> (&hidden)[10], int source_col){
  // Draw a card from the left and deal it to the source column of the deck
  char card = left.back();
  left.pop_back();
  source_pile.push_back(card);
  // Since this hidden card is now opened, delete the dot representing the hidden card on the gameboard
  hidden[source_col].pop_back();
}
