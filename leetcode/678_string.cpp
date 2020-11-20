#include "gtest/gtest.h"

#include <string>
#include <vector>

class Solution {
public:
    bool checkValidString(const std::string& s)
    {
        auto leftParenthesis{0};
        for (auto i{0U}; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '*') {
                ++leftParenthesis;
            }
            else {
                --leftParenthesis;
            }

            if (leftParenthesis < 0) {
                return false;
            }
        }

        if (leftParenthesis == 0) {
            return true;
        }

        auto rightParenthesis{0};
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') {
                ++rightParenthesis;
            }
            else {
                --rightParenthesis;
            }

            if (rightParenthesis < 0) {
                return false;
            }
        }

        return true;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().checkValidString("(*))"), true);
}
