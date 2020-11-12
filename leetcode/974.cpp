#include "gtest/gtest.h"

#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    int subarrayDivByK(const std::vector<int>& A, int K)
    {
        auto count{0U};
        auto size{A.size()};
        auto sum_map = std::map<int, int>{};
        auto currentSum{0};
        sum_map[0] = 1;

        for (auto i{0U}; i < size; ++i) {
            currentSum = (currentSum + A[i]) % K;
            if (currentSum < 0) {
                currentSum += K;
            }

            count += sum_map[currentSum];
            sum_map[currentSum] += 1;
        }

        return count;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().subarrayDivByK({4, 5, 0, -2, -3, 1}, 5), 7);
}
