#include "collect.hpp"
#include <iostream>
#include <string>
using namespace std;

void collect(vector<char> (&a)[], int arraysize)
{
    for (int i=0; i<arraysize; i++){
        int size = a[i].size();
        if (size<13){
            continue;
        }
        string straight="A23456789TJQK";
        bool isstraight=true;
        for (int j = 0; j < 13; i++) {
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
            }
    }
}
