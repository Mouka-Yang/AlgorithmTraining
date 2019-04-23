/*
Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int pa = a.size()-1, pb = b.size()-1;
        char da, db, carry = 0;
        while (pa >= 0 || pb >= 0 || carry) {
            da = pa >= 0 ? a[pa--] - '0' : 0;
            db = pb >= 0 ? b[pb--] - '0' : 0;
            sum = ((da ^ db ^ carry) ? '1' : '0') + sum;
            carry = (da + db + carry > 1);
        }
        return sum;
    }
};

int main(){
    string a = "111011101", b = "110110111";
    cout << Solution().addBinary(a, b) << endl;
}