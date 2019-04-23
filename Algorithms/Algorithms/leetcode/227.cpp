/*
Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int calculate(string s)
    {
        auto last_num = 0, current_val = 0, current_num = 0;
        auto len = s.size();
        auto current_op = '+';
        for (auto i = 0; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                current_num = current_num * 10 + (s[i] - '0');
            }
            else if (s[i] != ' ')
            {
                if (current_op == '+')
                {
                    current_val += current_num;
                    last_num = current_num;
                }
                else if (current_op == '-')
                {
                    current_val -= current_num;
                    last_num = -current_num;
                }
                else if (current_op == '*')
                {
                    current_val = current_val - last_num + last_num * current_num;
                    last_num = last_num * current_num;
                }
                else if (current_op == '/')
                {
                    current_val = current_val - last_num + last_num / current_num;
                    last_num = last_num / current_num;
                }

                current_num = 0;
                current_op = s[i];
            }
        }

        if (current_op == '+')
        {
            current_val += current_num;
        }
        else if (current_op == '-')
        {
            current_val -= current_num;
        }
        else if (current_op == '*')
        {
            current_val = current_val - last_num + last_num * current_num;
        }
        else if (current_op == '/')
        {
            current_val = current_val - last_num + last_num / current_num;
        }

        cout << current_val << "\n";
        return current_val;
    }
};

int main()
{
    string s = "1+2*5/3+6/4*2";
    Solution().calculate(s);
}