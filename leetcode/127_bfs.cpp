#include "gtest/gtest.h"

#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int ladderLength(
        const std::string& beginWord, const std::string& endWord, std::vector<std::string>& wordList)
    {
        std::unordered_set<std::string> wordSet{wordList.cbegin(), wordList.cend()};
        if (wordSet.count(endWord) == 0) {
            return 0;
        }

        std::unordered_set<int> seen{};
        std::deque<int> queue{};
        wordList.push_back(beginWord);

        queue.push_back(wordList.size() - 1);
        auto res{0};

        while (!queue.empty()) {
            auto len{queue.size()};
            for (auto i{0}; i < len; ++i) {
                auto curr{queue.front()};
                queue.pop_front();

                auto candidates{findCandidates(curr, wordList)};
                for (const auto& candidate : candidates) {
                    if (seen.count(candidate) == 0) {
                        if (wordList[candidate] == endWord) {
                            return res + 2;
                        }
                        seen.insert(candidate);
                        queue.push_back(candidate);
                    }
                }
            }
            ++res;
        }

        return 0;
    }

    std::vector<int> findCandidates(size_t wordIndex, const std::vector<std::string>& wordSet)
    {
        std::vector<int> res{};
        auto len{wordSet[wordIndex].size()};
        auto setLen{wordSet.size()};

        for (auto j{0}; j < setLen; ++j) {
            auto diff{0};
            for (auto i{0}; i < len; ++i) {
                if (wordSet[wordIndex][i] != wordSet[j][i]) {
                    diff++;
                }
                if (diff > 1) {
                    break;
                }
            }

            if (diff == 1) {
                res.push_back(j);
            }
        }

        return res;
    }
};

TEST(SolutionTest, Test)
{
    std::vector<std::string> input{"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(Solution().ladderLength("hit", "cog", input), 5);
}
