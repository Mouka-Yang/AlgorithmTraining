/*
Multiply Strings
Medium

919

415

Favorite

Share
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
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

class Solution
{

  public:
    string multiply(string num1, string num2)
    {
        vector<int> total(num1.size() + num2.size(), 0);
        stringstream res;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                auto mul =  (num1[i] - '0') * (num2[j] - '0');
                auto sum = mul + total[i+j+1];
                total[i+j+1] = sum % 10;
                total[i+j] += sum / 10;
            }
        }
        auto start = 0;
        for (; start < total.size() && total[start] == 0; start++){
            if (start >= 1)  return "0";
        }

        copy(total.begin() + start, total.end(), ostream_iterator<int>(res, ""));
        return res.str().c_str();
    }
};

int main()
{
    string num1 = "0", num2 = "0";
    cout << Solution().multiply(num1, num2) << endl;
}