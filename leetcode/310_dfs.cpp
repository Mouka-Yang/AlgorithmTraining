#include <algorithm>
#include <gtest/gtest.h>
#include <map>
#include <vector>

class Solution {
public:
    enum class VisitStatus { VISITED, NONVISTED };

    int getHeightByDFS(
        const std::vector<std::vector<int>>& adjecentList, std::vector<VisitStatus>& visited, int node)
    {
        int maxHeight{0};
        const auto& neighbors{adjecentList.at(node)};
        std::for_each(
            neighbors.cbegin(), neighbors.cend(),
            [&maxHeight, &visited, this, &adjecentList](const auto& neighbor) {
                if (visited[neighbor] == VisitStatus::NONVISTED) {
                    // todo
                    visited[neighbor] = VisitStatus::VISITED;
                    auto heightOfSubtree = getHeightByDFS(adjecentList, visited, neighbor);
                    maxHeight = maxHeight > heightOfSubtree + 1 ? maxHeight : heightOfSubtree+1;
                }
            });

        return maxHeight;
    }

    std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> adjecentList(n);

        std::for_each(edges.cbegin(), edges.cend(), [&adjecentList](const auto& edge) {
            adjecentList[edge[0]].push_back(edge[1]);
            adjecentList[edge[1]].push_back(edge[0]);
        });

        std::map<int, std::vector<int>> heightToRootMap{};

        std::vector<VisitStatus> visited(n, VisitStatus::NONVISTED);
        for (auto i{0}; i < adjecentList.size(); ++i) {
            visited[i] = VisitStatus::VISITED;
            auto height = getHeightByDFS(adjecentList, visited, i);

            heightToRootMap[height].push_back(i);

            visited.assign(visited.size(), VisitStatus::NONVISTED);
        }

        if (heightToRootMap.empty()) {
            return {};
        }
        return heightToRootMap.cbegin()->second;
    }
};

TEST(SolutionTest, Test)
{
    std::vector<std::vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    EXPECT_EQ(Solution().findMinHeightTrees(6, edges), std::vector<int>({3, 4}));
}
