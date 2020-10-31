#include "gtest/gtest.h"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    void init(size_t size)
    {
        ranks.resize(size, 0);
        parents.resize(size);
        std::iota(parents.begin(), parents.end(), 0);
    }

    size_t findNode(size_t node)
    {
        if (parents[node] != node) {
            parents[node] = findNode(parents[node]);
        }
        return parents[node];
    }

    void unionNode(size_t nodeX, size_t nodeY)
    {
        auto parentX = findNode(nodeX);
        auto parentY = findNode(nodeY);
        if (parentX != parentY) {
            if (ranks[parentX] <= ranks[parentY]) {
                parents[parentX] = parentY;
                if (ranks[parentX] == ranks[parentY]) {
                    ++ranks[parentY];
                }
            }
            else {
                parents[parentY] = parentX;
            }
        }
    }

    size_t getGroupCount()
    {
        auto count{0U};
        for (size_t i{0}; i < parents.size(); ++i) {
            if (i == findNode(i)) {
                ++count;
            }
        }
        return count;
    }

    int findCircleNum(std::vector<std::vector<int>>& M)
    {
        if (M.size() == 0) {
            return -1;
        }

        auto rowSize = M[0].size();
        auto colSize = M.size();
        init(rowSize);
        for (size_t rowNum = 0; rowNum < rowSize; ++rowNum) {
            for (size_t colNum = 0; colNum < colSize; ++colNum) {
                if (M[rowNum][colNum] == 1 && rowNum != colNum) {
                    unionNode(rowNum, colNum);
                }
            }
        }

        return getGroupCount();
    }

private:
    std::vector<size_t> ranks{};
    std::vector<size_t> parents{};
};

TEST(Test547, Test)
{
    auto input = std::vector<std::vector<int>>{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    EXPECT_EQ(Solution().findCircleNum(input), 2);

    auto input2 = std::vector<std::vector<int>>{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    EXPECT_EQ(Solution().findCircleNum(input2), 1);
}
