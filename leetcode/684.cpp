#include "gtest/gtest.h"
#include <algorithm>
#include <cstddef>
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

    std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges)
    {
        init(edges.size());

        std::for_each(edges.cbegin(), edges.cend(), [this](const auto& edge) { checkDuplicate(edge); });
        return dup;
    }

    void checkDuplicate(const std::vector<int>& edge)
    {
        auto nodeX = edge[0] - 1;
        auto nodeY = edge[1] - 1;
        auto parentX = findNode(nodeX);
        auto parentY = findNode(nodeY);
        if (parentX == parentY) {
            dup[0] = nodeX + 1;
            dup[1] = nodeY + 1;
        }
        else {
            unionNode(nodeX, nodeY);
        }
    }

private:
    std::vector<size_t> ranks;
    std::vector<size_t> parents;
    std::vector<int> dup{0,0};
};

TEST(TestSolution, Test)
{
    auto input = std::vector<std::vector<int>>{{1, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ(Solution().findRedundantConnection(input), std::vector<int>({2,3}));

    auto input2 = std::vector<std::vector<int>>{{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    EXPECT_EQ(Solution().findRedundantConnection(input2), std::vector<int>({1,4}));
}
