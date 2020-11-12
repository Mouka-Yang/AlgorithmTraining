#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddress(std::string s)
    {
        backtrack(s, "", 0, 0);

        return res;
    }

    void backtrack(const std::string& s, std::string currIp, int start, int section)
    {
        if (section == 4) {
            if (start == s.size()) {
                currIp.pop_back();
                res.push_back(currIp);
            }
            return;
        }

        for (auto i{1}; i <= 3; ++i) {
            auto currSection{s.substr(start, i)};
            if ((currSection.size() > 1 && currSection[0] == '0') || std::stoi(currSection) > 255) {
                break;
            }

            backtrack(s, currIp + currSection + '.', start + i, section + 1);
        }
    }

    std::vector<std::string> res{};
    std::string currIp{};
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(
        Solution().restoreIpAddress("25525511135"),
        std::vector<std::string>({"255.255.11.135", "255.255.111.35"}));
}
