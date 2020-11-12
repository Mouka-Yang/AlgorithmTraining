#include "gtest/gtest.h"

#include <algorithm>
#include <map>
#include <stack>
#include <vector>
class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::map<int, std::vector<int>> adjecentMap{};
        std::vector<int> indegreeOfNodes(numCourses, 0);
        std::vector<int> zeroDegreeNodes{};
        std::vector<int> res{};

        std::for_each(
            prerequisites.cbegin(), prerequisites.cend(), [&adjecentMap, &indegreeOfNodes](const auto& edge) {
                ++indegreeOfNodes[edge[0]];
                adjecentMap[edge[1]].push_back(edge[0]);
            });

        for (auto i{0}; i < indegreeOfNodes.size(); ++i) {
            if (indegreeOfNodes[i] == 0) {
                zeroDegreeNodes.push_back(i);
            }
        }

        while (!zeroDegreeNodes.empty()) {
            auto currentNode = zeroDegreeNodes.back();
            zeroDegreeNodes.pop_back();

            res.push_back(currentNode);

            auto& neighborsOfCurrentNode{adjecentMap[currentNode]};
            std::for_each(
                neighborsOfCurrentNode.cbegin(), neighborsOfCurrentNode.cend(),
                [&zeroDegreeNodes, &indegreeOfNodes](const auto& neighbor) {
                    if (--indegreeOfNodes[neighbor] == 0) {
                        zeroDegreeNodes.push_back(neighbor);
                    }
                });
        }

        return res;
    }
};

TEST(SolutionTest, Test)
{
    std::vector<std::vector<int>> pres{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    EXPECT_EQ(Solution().findOrder(4, pres), std::vector<int>({0, 2, 1, 3}));
}
