#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>
using namespace testing;

class Solution {
public:
    using QueueType = std::vector<std::vector<int>>;
    QueueType getPeopleByLevel(const QueueType& people, size_t level)
    {
        QueueType res{};
        for (const auto& person : people) {
            if (person[1] == level) {
                res.push_back(person);
            }
        }

        return res;
    }

    void insertLevelByPeople(const QueueType& currentLevelPeople)
    {
        for (int i = currentLevelPeople.size() - 1; i >= 0; --i) {
            auto currentWeight{currentLevelPeople[i][0]};
            auto remainLevel{currentLevelPeople[i][1]};
            auto insertPos{res.size()};
            for (auto j{0U}; j < res.size(); ++j) {
                if (res[j][0] < currentWeight) {
                    continue;
                }
                --remainLevel;
                if (remainLevel == 0) {
                    insertPos = j + 1;
                    break;
                }
            }

            res.insert(res.begin() + insertPos, currentLevelPeople[i]);
        }
    }

    std::vector<std::vector<int>> ReconstructQueue(const std::vector<std::vector<int>>& people)
    {
        auto peopleSize{people.size()};

        for (auto level{0U}; level < 1100 && res.size() < peopleSize; ++level) {
            auto currentLevelPeople{getPeopleByLevel(people, level)};
            if (currentLevelPeople.empty()) {
                continue;
            }

            std::sort(
                currentLevelPeople.begin(), currentLevelPeople.end(),
                [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

            if (level == 0) {
                res.insert(res.end(), currentLevelPeople.begin(), currentLevelPeople.end());
                continue;
            }

            insertLevelByPeople(currentLevelPeople);
        }

        return res;
    }

private:
    QueueType res{};
};

TEST(SolutionTest, Test)
{
    Solution::QueueType input{{8, 0}, {4, 4}, {8, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto res = Solution().ReconstructQueue(input);

    Solution::QueueType expected{{5, 0}, {8, 0}, {5, 2}, {6, 1}, {4, 4}, {8, 1}};

    EXPECT_EQ(res, expected);
}
