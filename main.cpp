#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <random>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "board.h"
#include "move.h"
#include "deal.h"
#include "collect.h"
#include "success.h"
#include "deal_hide.h"
#include "newgame.h"

using namespace std;

int main() {

  //print game rules to the user
  cout << "Welcome to Spider Solitaire!" << endl;
  cout << endl;
  cout << "***** GAME RULES *****" << endl;
  cout << "1. The object of the game is to eliminate all the cards on the table by constructing columns of cards." << endl; 
  cout << "2. Each column should be arranged in descending order from K to A." << endl;
  cout << "3. You can move cards between columns in the correct order (K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2, A) to organize the columns." << endl;
  cout << "4. If you have an empty column, you can move any card or any consecutive deck to it." << endl;
  cout << "5. You could deal a new row if there's no card to move." << endl;
  cout << "6. But note - you can't deal new cards when you have any empty columns." << endl;
  cout << "7. When the cards are arranged in the right order, they can be eliminated." << endl;
  cout << "8. Eliminated all the cards to win the game!" << endl;
  cout << endl;

  cout << "Enter 1 to begin the new game; Enter 2 to continue the game." << endl;

  int choice;

  //create a left deck
  vector<char> left;
  //create an array of shown decks
  const int numdeck=10;
  vector<char> deck[numdeck];
  //create an array of unshown decks
  int num_set_deal;
  vector<char> hidden[numdeck];
  
  bool yesbegin=false;
  while (yesbegin==false){
    cin >> choice;
    if (choice==1){
      newgame(left, deck, hidden, num_set_deal);
      yesbegin=true;
    }
    else if (choice==2){
      ifstream inleft ("myleft.txt");
      if (inleft.fail()){
        cout << "No past game status found. New game begins." << endl;
        newgame(left, deck, hidden, num_set_deal);
        break;
      } else {
        char x;
        while (inleft >> x){
          left.push_back(x);
        }
        inleft.close();
      }
      ifstream indeck0 ("mydeck0.txt");
      char x0;
      while (indeck0 >> x0){
        deck[0].push_back(x0);
      }
      indeck0.close();
      ifstream indeck1 ("mydeck1.txt");
      char x1;
      while (indeck1 >> x1){
        deck[1].push_back(x1);
      }
      indeck1.close();
      ifstream indeck2 ("mydeck2.txt");
      char x2;
      while (indeck2 >> x2){
        deck[2].push_back(x2);
      }
      indeck2.close();
      ifstream indeck3 ("mydeck3.txt");
      char x3;
      while (indeck3 >> x3){
        deck[3].push_back(x3);
      }
      indeck3.close();
      ifstream indeck4 ("mydeck4.txt");
      char x4;
      while (indeck4 >> x4){
        deck[4].push_back(x4);
      }
      indeck4.close();
      ifstream indeck5 ("mydeck5.txt");
      char x5;
      while (indeck5 >> x5){
        deck[5].push_back(x5);
      }
      indeck5.close();
      ifstream indeck6 ("mydeck6.txt");
      char x6;
      while (indeck6 >> x6){
        deck[6].push_back(x6);
      }
      indeck6.close();
      ifstream indeck7 ("mydeck7.txt");
      char x7;
      while (indeck7 >> x7){
        deck[7].push_back(x7);
      }
      indeck7.close();
      ifstream indeck8 ("mydeck8.txt");
      char x8;
      while (indeck8 >> x8){
        deck[8].push_back(x8);
      }
      indeck8.close();
      ifstream indeck9 ("mydeck9.txt");
      char x9;
      while (indeck9 >> x9){
        deck[9].push_back(x9);
      }
      indeck9.close();
      ifstream innum ("mynum.txt");
      innum >> num_set_deal;
      innum.close();
      ifstream inhid0 ("myhid0.txt");
      char y0;
      while (inhid0 >> y0){
        hidden[0].push_back(y0);
      }
      inhid0.close();
      ifstream inhid1 ("myhid1.txt");
      char y1;
      while (inhid1 >> y1){
        hidden[1].push_back(y1);
      }
      inhid1.close();
      ifstream inhid2 ("myhid2.txt");
      char y2;
      while (inhid2 >> y2){
        hidden[2].push_back(y2);
      }
      inhid2.close();
      ifstream inhid3 ("myhid3.txt");
      char y3;
      while (inhid3 >> y3){
        hidden[3].push_back(y3);
      }
      inhid3.close();
      ifstream inhid4 ("myhid4.txt");
      char y4;
      while (inhid4 >> y4){
        hidden[4].push_back(y4);
      }
      inhid4.close();
      ifstream inhid5 ("myhid5.txt");
      char y5;
      while (inhid5 >> y5){
        hidden[5].push_back(y5);
      }
      inhid5.close();
      ifstream inhid6 ("myhid6.txt");
      char y6;
      while (inhid6 >> y6){
        hidden[6].push_back(y6);
      }
      inhid6.close();

      ifstream inhid7 ("myhid7.txt");
      char y7;
      while (inhid7 >> y7){
        hidden[7].push_back(y7);
      }
      inhid7.close();
      ifstream inhid8 ("myhid8.txt");
      char y8;
      while (inhid8 >> y8){
        hidden[8].push_back(y8);
      }
      inhid8.close();
      ifstream inhid9 ("myhid9.txt");
      char y9;
      while (inhid9 >> y9){
        hidden[9].push_back(y9);
      }
      inhid9.close();
      yesbegin=true;
    }
  }
  
  //game begins.
  int option;
  bool ifquit=false;
  while(!success(deck, numdeck)){ 
    //print the game board
    board(deck, hidden, num_set_deal, numdeck);

    cout << "You have 3 options: Enter 1 to move the card; Enter 2 to deal the cards from the card shuffler; Enter 3 to quit the game and save the status." << endl;
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (option == 1){
      string input;
      bool yesmove=false;
      cout << "Please enter the move instruction (format: num_of_source_deck num_of_moved_cards num_of_destination_deck):" << endl;
      while(!yesmove){
        getline(cin, input);
        istringstream iss(input);
        int srcId, num, destId;
        if (iss >> srcId >> num >> destId) {
          if (move(deck[srcId], num, deck[destId], hidden, left, srcId)) {
            cout << "Move successfully！" << endl;
            yesmove=true;
          } else {
            cout << "Move failed！ Please retry." << endl;
          }
        } 
        else {
          cout << "Wrong format! Please retry." << endl;
        }
      }     
    }
    else if (option == 2){
      int notEmpty = true;
      for (int i=0; i<numdeck; i++){
        if (deck[i].empty()){
          notEmpty = false;
        }
      }
      if (num_set_deal>0){
        if (notEmpty){
          deal(left, deck, num_set_deal);
        }
        else{
          cout << "Please fill the empty columns before dealing cards." << endl;
        }
      }
      else{
        cout << "No cards to deal." << endl;
      }
    }
    else if (option == 3){
      ifquit=true;
      ofstream myleft;
      myleft.open("myleft.txt");
      for (int i=0; i<left.size(); i++){
        myleft << left[i] << endl;
      }
      myleft.close();
      ofstream mydeck0;
      mydeck0.open("mydeck0.txt");
      for (int i=0; i<deck[0].size(); i++){
        mydeck0 << deck[0][i] << endl;
      }
      mydeck0.close();
      ofstream mydeck1;
      mydeck1.open("mydeck1.txt");
      for (int i=0; i<deck[1].size(); i++){
        mydeck1 << deck[1][i] << endl;
      }
      mydeck1.close();
      ofstream mydeck2;
      mydeck2.open("mydeck2.txt");
      for (int i=0; i<deck[2].size(); i++){
        mydeck2 << deck[2][i] << endl;
      }
      mydeck2.close();
      ofstream mydeck3;
      mydeck3.open("mydeck3.txt");
      for (int i=0; i<deck[3].size(); i++){
        mydeck3 << deck[3][i] << endl;
      }
      mydeck3.close();
      ofstream mydeck4;
      mydeck4.open("mydeck4.txt");
      for (int i=0; i<deck[4].size(); i++){
        mydeck4 << deck[4][i] << endl;
      }
      mydeck4.close();
      ofstream mydeck5;
      mydeck5.open("mydeck5.txt");
      for (int i=0; i<deck[5].size(); i++){
        mydeck5 << deck[5][i] << endl;
      }
      mydeck5.close();
      ofstream mydeck6;
      mydeck6.open("mydeck6.txt");
      for (int i=0; i<deck[6].size(); i++){
        mydeck6 << deck[6][i] << endl;
      }
      mydeck6.close();
      ofstream mydeck7;
      mydeck7.open("mydeck7.txt");
      for (int i=0; i<deck[7].size(); i++){
        mydeck7 << deck[7][i] << endl;
      }
      mydeck7.close();
      ofstream mydeck8;
      mydeck8.open("mydeck8.txt");
      for (int i=0; i<deck[8].size(); i++){
        mydeck8 << deck[8][i] << endl;
      }
      mydeck8.close();
      ofstream mydeck9;
      mydeck9.open("mydeck9.txt");
      for (int i=0; i<deck[9].size(); i++){
        mydeck9 << deck[9][i] << endl;
      }
      mydeck9.close();
      ofstream mynum;
      mynum.open("mynum.txt");
      mynum << num_set_deal << endl;
      mynum.close();
      ofstream myhid0;
      myhid0.open("myhid0.txt");
      for (int i=0; i<hidden[0].size(); i++){
        myhid0 << hidden[0][i] << endl;
      }
      myhid0.close();
      ofstream myhid1;
      myhid1.open("myhid1.txt");
      for (int i=0; i<hidden[1].size(); i++){
        myhid1 << hidden[1][i] << endl;
      }
      myhid1.close();
      ofstream myhid2;
      myhid2.open("myhid2.txt");
      for (int i=0; i<hidden[2].size(); i++){
        myhid2 << hidden[2][i] << endl;
      }
      myhid2.close();
      ofstream myhid3;
      myhid3.open("myhid3.txt");
      for (int i=0; i<hidden[3].size(); i++){
        myhid3 << hidden[3][i] << endl;
      }
      myhid3.close();
      ofstream myhid4;
      myhid4.open("myhid4.txt");
      for (int i=0; i<hidden[4].size(); i++){
        myhid4 << hidden[4][i] << endl;
      }
      myhid4.close();
      ofstream myhid5;
      myhid5.open("myhid5.txt");
      for (int i=0; i<hidden[5].size(); i++){
        myhid5 << hidden[5][i] << endl;
      }
      myhid5.close();
      ofstream myhid6;
      myhid6.open("myhid6.txt");
      for (int i=0; i<hidden[6].size(); i++){
        myhid6 << hidden[6][i] << endl;
      }
      myhid6.close();
      ofstream myhid7;
      myhid7.open("myhid7.txt");
      for (int i=0; i<hidden[7].size(); i++){
        myhid7 << hidden[7][i] << endl;
      }
      myhid7.close();
      ofstream myhid8;
      myhid8.open("myhid8.txt");
      for (int i=0; i<hidden[8].size(); i++){
        myhid8 << hidden[8][i] << endl;
      }
      myhid8.close();
      ofstream myhid9;
      myhid9.open("myhid9.txt");
      for (int i=0; i<hidden[9].size(); i++){
        myhid9 << hidden[9][i] << endl;
      }
      myhid9.close();
      break;
    }
    else {
      cout << "Wrong option. Please retry." << endl;
    }

    // after move/deal, collect the straight if any
    collect(deck, numdeck, left, hidden);
  }

  if (ifquit==true){
    cout << "Game over!" << endl;
  }
  else{
    cout << "####################"<<endl;
    cout << "# Congratulations! #"<<endl; 
    cout << "# You win the game #"<<endl;
    cout << "####################"<<endl;
  } 
  return 0;
}