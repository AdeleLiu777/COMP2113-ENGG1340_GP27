#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "board.hpp"
#include "move.hpp"
#include "deal.hpp"
#include "collect.hpp"
#include "success.hpp"

using namespace std;

int main() {
    
    //create a left card deck
    vector<char> left;
    for (int i=0; i<4; i++){
        left.push_back('A');
    }
    for (int i=0; i<4; i++){
        left.push_back('J');
    }
    for (int i=0; i<4; i++){
        left.push_back('Q');
    }
    for (int i=0; i<4; i++){
        left.push_back('K');
    }
    for (int i=0; i<4; i++){
        left.push_back('T');
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<8; j++){
            left.push_back('2'+j);
        }
    }
    
    //create a array of shown decks
    int numdeck=10;
    vector<char> deck[numdeck];
    
    //add cards to the shown decks
    for (int i=0; i<numdeck; i++ ){
        srand(static_cast<unsigned int>(std::time(nullptr)));
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, left.size() - 1);
        int selectedIndex = dist(gen);
        deck[0].push_back(left[selectedIndex]);
        
        //remove selected cards from the left deck
        left.erase(left.begin() + selectedIndex);
    }
    
    //print game rules to the user
    //not finished
    
    //print the game board to the user
    board();
    
    //user has two options: 1) moves the card; 2) deal the cards from the left deck
    move();
    deal();
    
    //after each move, determine whether the card could be collected
    collect(deck, numdeck);
    
    //then determine whether the game should 1) continue 2) success(over)
    //if continue, then continue looping; if success, the loop is over
    success();
    
    //in the loop, if continue, then show the board() again, and repeat steps above
    
    //when success() returns "True", we will print the message below and end the game
    cout << "Congratulation! You finished the game." << endl;
    
    return 0;
}
