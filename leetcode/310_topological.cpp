#include "gtest/gtest.h"

#include <algorithm>
#include <deque>
#include <vector>

class Solution {
public:
    enum class VisitStatus { VISITED, NONVISITED };

    std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> adjacentList(n);
        std::vector<int> degreeOfNodes(n, 0);

        std::for_each(edges.cbegin(), edges.cend(), [&adjacentList, &degreeOfNodes](const auto& edge) {
            adjacentList[edge[0]].push_back(edge[1]);
            adjacentList[edge[1]].push_back(edge[0]);
            ++degreeOfNodes[edge[0]];
            ++degreeOfNodes[edge[1]];
        });

        std::deque<int> leafNodes{};
        for (auto i{0}; i < n; ++i) {
            if (degreeOfNodes[i] == 1) {
                leafNodes.push_back(i);
            }
        }

        auto remainedNodeNum{n};
        auto currentLeafNodeNum{0};
        auto totalLeafNodeNum{leafNodes.size()};
        auto nextLeafNodeNum{0};
        auto height{0};

        while (remainedNodeNum > 2) {
            auto currentLeafNode{leafNodes.front()};
            leafNodes.pop_front();

            auto currentAdjacentList{adjacentList[currentLeafNode]};
            for (const auto& node : currentAdjacentList) {
                if (--degreeOfNodes[node] == 1) {
                    degreeOfNodes[node] = 0;
                    leafNodes.push_back(node);
                    ++nextLeafNodeNum;
                }
            }

            ++currentLeafNodeNum;

            if (currentLeafNodeNum >= totalLeafNodeNum) {
                remainedNodeNum -= totalLeafNodeNum;
                currentLeafNodeNum = 0;
                totalLeafNodeNum = nextLeafNodeNum;
                nextLeafNodeNum = 0;
                height++;
            }
        }

        return std::vector<int>(leafNodes.cbegin(), leafNodes.cend());
    }
};

TEST(SolutionTest, Test)
{
    std::vector<std::vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    EXPECT_EQ(Solution().findMinHeightTrees(6, edges), std::vector<int>({3, 4}));
}
