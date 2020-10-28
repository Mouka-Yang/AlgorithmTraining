#include "gtest/gtest.h"
#include "header.h"

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& T)
    {
        std::stack<int> s;
        auto numSize = T.size();
        auto res = std::vector<int>(numSize);
        for (int i = numSize - 1; i >= 0; --i) {
            while (!s.empty() && T[s.top()] <= T[i]) {
                s.pop();
            }

            if (!s.empty()) {
                res[i] = s.top() - i;
            }
            else {
                res[i] = 0;
            }

            s.push(i);
        }

        return res;
    }
};

TEST(SolutionTest, Test)
{
    auto res = Solution().dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73});
    EXPECT_EQ(res, std::vector<int>({1, 1, 4, 2, 1, 1, 0, 0}));
}
