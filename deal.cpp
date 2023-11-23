//
//  deal.cpp
//  comp2113_gp27
//
//  Created by 刘书扬 on 21/11/2023.
//

#include "deal.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


void dealNewCards(std::vector<Left>& deck, std::vector<std::vector<Left>>& gameBoard) {
    std::random_device rd;
    std::mt19937 gen(rd());

    int numCardsToDeal = 10;  // Number of cards dealt

    // random shuffle
    std::shuffle(deck.begin(), deck.end(), gen);

    // Draws cards from the pile and deals them to each column of the game screen
    for (int col = 0; col < gameBoard.size(); ++col) {
        for (int i = 0; i < numCardsToDeal; ++i) {
            // Get the cards at the top of the pile and place them at the end of the columns on the game screen
            std::string card = deck.back();
            deck.pop_back();
            gameBoard[col].push_back(card);
        }
    }
}
