#include "gtest/gtest.h"

#include <deque>
#include <string>
#include <vector>
class Solution {
public:
    bool wordBreak(std::string s, const std::vector<std::string>& wordDict)
    {
        std::deque<std::string> remainWordQueue{};
        remainWordQueue.push_back(s);

        auto found{false};
        while (!remainWordQueue.empty() && !found) {
            auto currWord{remainWordQueue.front()};
            remainWordQueue.pop_front();

            auto nextRemainWords{getNextRemainWords(currWord, wordDict)};
            for (const auto& remainWord : nextRemainWords) {
                if (remainWord.empty()) {
                    found = true;
                    break;
                }

                remainWordQueue.push_back(remainWord);
            }
        }

        return found;
    }

    std::vector<std::string> getNextRemainWords(
        const std::string& currWord, const std::vector<std::string>& wordDict)
    {
        std::vector<std::string> res{};
        for (const auto& word : wordDict) {
            auto i{0};
            auto exit{false};
            auto wordSize{word.size()};
            while (!exit) {
                if (i > 0) {
                    res.push_back(currWord.substr(i * word.size()));
                }

                for (auto j{0}; j < wordSize; ++j) {
                    if (currWord[wordSize * i + j] != word[j]) {
                        exit = true;
                        break;
                    }
                }

                ++i;
            }
        }
        return res;
    }
};

TEST(SolutionTest, Test)
{
    std::string s{"catsanddog"};
    std::vector<std::string> w{"cats", "dog", "sand", "and", "cat"};
    EXPECT_EQ(Solution().wordBreak(s, w), true);
}

TEST(SolutionTest, Test2)
{
    std::string s{"aaaaaaaaaaaaaaaaaaaaaa"};
    std::vector<std::string> w{"aaa", "a"};
    EXPECT_EQ(Solution().wordBreak(s, w), true);
}

TEST(SolutionTest, Test3)
{
    std::string s{"catskicatcats"};
    std::vector<std::string> w{"cats", "cat", "dog", "ski"};
    EXPECT_EQ(Solution().wordBreak(s, w), true);
}
