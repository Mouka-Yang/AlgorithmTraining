#include "gtest.bak/gtest.h"

#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target)
    {
        std::unordered_set<std::string> dead_set{deadends.cbegin(), deadends.cend()};
        if (dead_set.count("0000") != 0) {
            return -1;
        }

        if (target == "0000") {
            return 0;
        }

        std::deque<std::string> queue{};
        queue.emplace_back("0000");

        std::unordered_set<std::string> seen{};
        auto found{false};
        auto res{0};

        while (!queue.empty() && !found) {
            auto currLen{queue.size()};
            for (auto i{0}; i < currLen; ++i) {
                auto currLock{queue.front()};
                queue.pop_front();

                auto candidates{getNextCandidates(currLock)};

                for (const auto& candidate : candidates) {
                    if (seen.count(candidate) == 0 && dead_set.count(candidate) == 0) {
                        if (candidate == target) {
                            found = true;
                            break;
                        }

                        seen.insert(candidate);
                        queue.push_back(candidate);
                    }
                }
            }
            ++res;
        }

        return found ? res : -1;
    }

    std::vector<std::string> getNextCandidates(std::string lock)
    {
        std::vector<std::string> res(8);

        for (auto& c : lock) {
            auto tmp{c};
            c = tmp == '0' ? '9' : tmp - 1;
            res.push_back(lock);
            c = tmp == '9' ? '0' : tmp + 1;
            res.push_back(lock);

            c = tmp;
        }

        return res;
    }
};

TEST(SolutionTest, Test)
{
    auto input = std::vector<std::string>{"0201", "0101", "0102", "1212", "2002"};
    EXPECT_EQ(Solution().openLock(input, "0202"), 6);
}
