#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

void newgame(vector<char> &left, vector<char> (&deck)[10], vector<char> (&hidden)[10], int &num_set_deal){
  //create a left card deck
  for (int i=0; i<8; i++){
      left.push_back('A');
  }
  for (int i=0; i<8; i++){
      left.push_back('J');
  }
  for (int i=0; i<8; i++){
      left.push_back('Q');
  }
  for (int i=0; i<8; i++){
      left.push_back('K');
  }
  for (int i=0; i<8; i++){  
      left.push_back('T');
  }
  for (int i=0; i<8; i++){
      for (int j=0; j<8; j++){
          left.push_back('2'+j);
      }
  }

  //shuffle the left
  random_device rd;
  mt19937 gen(rd());
  shuffle(left.begin(), left.end(), gen);

  //add cards to the shown decks
  for (int i=0; i<10; i++ ){
      deck[i].push_back(left.back());
      left.pop_back();
  }

  //add dots to the unshown decks
  num_set_deal = 5;
  for (int i=0;i<10;i++){
    char dot='.';
    for (int j=0;j<4;j++){
      hidden[i].push_back(dot);
    }
    if (i==0 || i==1 || i==2 || i==3){
      hidden[i].push_back(dot);
    }
  }
}