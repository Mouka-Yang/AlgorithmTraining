#include "gtest/gtest.h"

#include <string>
#include <vector>

class Solution {
public:
    bool checkValidString(const std::string& s)
    {
        std::vector<char> notRightChars{};
        auto len{s.size()};

        for (auto i{0}; i < len; ++i) {
            if (s[i] == '(' || s[i] == '*') {
                notRightChars.push_back(s[i]);
            }
            else {
                if (notRightChars.empty()) {
                    return false;
                }

                notRightChars.pop_back();
            }
        }

        std::vector<char> leftChars{};
        len = notRightChars.size();
        for (auto i{0}; i < len; ++i) {
            if (s[i] == '(') {
                leftChars.push_back(s[i]);
            }
            else {
                if (!leftChars.empty()) {
                    leftChars.pop_back();
                }
            }
        }

        return leftChars.empty();
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().checkValidString("(*))"), true);
}
