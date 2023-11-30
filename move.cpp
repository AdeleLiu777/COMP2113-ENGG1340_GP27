#include "move.h"
#include "deal_hide.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

// 判断卡牌能否移动的函数，参数分别为源牌堆、移动数量和目标牌堆 A function that determines whether a card can be moved, with the parameters being the source pile, the number of moves, and the target pile.
bool move(vector<char>& src, int num, vector<char>& dest, vector<char> (&hidden)[10], vector<char>& left, int srcId) { 
    // 如果源牌堆为空或者移动数量超过源牌堆的牌数，无法移动 If the source pile is empty or the number of moves exceeds the number of cards in the source pile, it cannot be moved
    if (src.empty() || num > src.size()) {
        return false;
    }

    // 如果目标牌堆为空，只需要移动的牌是连续的数字即可 If the target pile is empty, only the moving cards need to be consecutive numbers
    if (dest.empty()) {
        vector<char> movingCards(src.end() - num, src.end());

        for (int i = 1; i < movingCards .size(); i++) {
            int curRank = strchr("A23456789TJQK", movingCards[i]) - "A23456789TJQK";
            int preRank = strchr("A23456789TJQK", movingCards[i-1]) - "A23456789TJQK";
            if (curRank != preRank - 1) {
                return false;
            }
        }
    } else {
        // 如果目标牌堆不为空，移动的牌必须是连续的数字，并且比目标牌堆顶上的牌小 1 If the target pile is not empty, the moved card must be a consecutive number and one smaller than the card at the top of the target pile
        vector<char> movingCards(src.end() - num, src.end());
        int topRank = strchr("A23456789TJQK", dest.back()) - "A23456789TJQK";

        for (int i = 1; i < movingCards.size(); i++) {
            int curRank = strchr("A23456789TJQK", movingCards[i]) - "A23456789TJQK";
            int preRank = strchr("A23456789TJQK", movingCards[i-1]) - "A23456789TJQK";
            if (curRank != preRank - 1) {
                return false;
            }
        }

        int bottomRank = strchr("A23456789TJQK", movingCards[0]) - "A23456789TJQK";
        if (topRank - bottomRank != 1) {
            return false;
        }
    }

    // 移动牌 move card
    vector<char> movingCards(src.end() - num, src.end());
    dest.insert(dest.end(), movingCards.begin(), movingCards.end());
    src.erase(src.end() - num, src.end());
    
    if (src.size()==0 && hidden[srcId].size()>0){
      deal_hide(left, src, hidden, srcId);
    }
    return true;
}
