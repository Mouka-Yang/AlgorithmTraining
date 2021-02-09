#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    int NumberOfMountainSeen(const std::vector<int>& height)
    {
        if (height.size() == 1) {
            return 0;
        }

        auto len{height.size()};
        auto leftHigher = countLeftHigherMountains(height);
        auto rightHigher = countRightHigherMountains(height);

        auto count{0U};
        for (auto i{0U}; i < len; ++i) {
            if (i % 2 != 0) {
                count += rightHigher[i];
            }
            else {
                count += leftHigher[i];
            }
        }

        return count;
    }

private:
    std::vector<int> countLeftHigherMountains(const std::vector<int>& heightList)
    {
        auto len{heightList.size()};
        std::vector<int> heightStack{};
        std::vector<int> leftHigher(heightList.size());

        for (int i = 0; i < len; ++i) {
            leftHigher[i] = heightStack.size();

            while (!heightStack.empty() && heightStack.back() <= heightList[i]) {
                heightStack.pop_back();
            }

            heightStack.push_back(heightList[i]);
        }

        return leftHigher;
    }

    std::vector<int> countRightHigherMountains(const std::vector<int>& heightList)
    {
        auto len{heightList.size()};
        std::vector<int> heightStack{};
        std::vector<int> rightHigher(heightList.size());

        for (int i = len - 1; i >= 0; --i) {
            rightHigher[i] = heightStack.size();

            while (!heightStack.empty() && heightStack.back() <= heightList[i]) {
                heightStack.pop_back();
            }

            heightStack.push_back(heightList[i]);
        }

        return rightHigher;
    }
};

TEST(A, A)
{
    EXPECT_EQ(Solution().NumberOfMountainSeen({16, 5, 3, 10, 21, 7}), 8);
    EXPECT_EQ(Solution().NumberOfMountainSeen({1, 3, 4, 4, 2}), 4);

    std::vector<int> a{1, 2, 3, 4, 5};
    auto l = a.rbegin();
    auto r = a.rend();
}
