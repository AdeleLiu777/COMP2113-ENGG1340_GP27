#include "collect.h"
#include "deal_hide.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void collect(vector<char> (&a)[10], int arraysize, vector<char> &left, vector<char> (&hidden)[10])
{
    for (int i=0; i<arraysize; i++){
        int size = a[i].size();
        if (size<13){
            continue;
        }
        string straight="KQJT98765432A";
        bool isstraight=true;
        for (int j = 0; j < 13; j++) {
                if (a[i][size - 13 + j] != straight[j]) {
                    isstraight = false;
                    break;
                }
            }
            
        if (isstraight) {
        // Found a straight, remove the elements
            for (int j = 0; j < 13; j++) {
                    a[i].pop_back();
            }
            if (a[i].size()==0 && hidden[i].size()>0){
                deal_hide(left, a[i], hidden, i);
            }
        }
    }
}
