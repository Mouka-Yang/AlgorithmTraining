#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto count = 0, max = 0;
        for (auto& c : s){
            if (c == '0'){
                max = max > count ? max : count;
                count = 0;
            }
            else count++;
        }        
        return max;
    }
};