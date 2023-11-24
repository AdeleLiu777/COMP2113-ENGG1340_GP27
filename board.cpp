#include "board.hpp"
#include <vector>
using namespace std;

void board(vector<char> (&deck)[], vector<char> (&hidecard)[]) {
  //print the title of each column 
  for (int i = 0; i < 10; i++) {
    cout <<" "<<i;
  }
  cout << endl;

  //count the length of the longest deck
  int max_length = 0;
  for (int col=0;col<10;col++){
    int deck_length=hidecard[col].size()+deck[col].size();
    if (deck_length>max_length){
      max_length=deck_length;
    }
  }
  
  //print the gameboard of hiding cards that are shown as dots and opened card that are shown as words
  for (int row=0;row<max_length;row++){
    cout<<row;
    for (int col=0;col<10;col++){
      if (hidecard[col].size()>=(row+1)){
        cout<<hidecard[col][row]<<" ";
      }
      else {
        int deckrow = row-hidecard[col].size();
        if (deck[col].size()>=(deckrow+1)){
          cout<<deck[col][deckrow]<<" ";
        }
        else{
          cout<<"  ";
        }
      } 
    }
    cout<<"\n";
  }
}
