#include <iostream>
#include <vector>
#include "success.h"

using namespace std;

bool success(vector<char> deck[], int numdeck) {
    // Check if all the decks are empty
    for (int i = 0; i < numdeck; i++) {
        if (!deck[i].empty()) {
            return false; 
        }
    }
    return true; // All decks are empty, game is successful
}