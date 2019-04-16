/*
Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

class Solution
{

  public:
    string multiply(string num1, string num2)
    {
        vector<int> total(num1.size() + num2.size(), 0);
        stringstream res;
        for (auto i = 0; i < num1.size(); i++){
            for (auto j = 0; j < num2.size(); j++){
                auto high_n = (num1[i] - '0') * (num2[j] - '0') / 10;
                auto low_n = (num1[i] - '0') * (num2[j] - '0') % 10;
                auto temp = total[i+j+1] + low_n;
                auto pre = temp / 10;
                total[i+j+1] = temp % 10;
                temp = total[i+j] + high_n + pre;
                pre = temp / 10;
                total[i+j] = temp % 10;
                for (auto k = i+j-1; k >=0 ; k--){
                    temp = total[k] + pre;
                    total[k] = temp % 10;
                    pre = temp / 10;
                    if (pre == 0) break;
                }
                for_each(total.begin(), total.end(), [](const int x ){cout << x ;});
                cout << endl;

            }
        }
        auto start = total[0] == 0 ? 1 : 0;
        copy(total.begin()+start, total.end(), ostream_iterator<int>(res, ""));
        return res.str().c_str();
    }
};

int main(){
    string n1 = "0", n2 = "0";
    cout << Solution().multiply(n1,n2) << endl;
}