#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>
using namespace testing;

class Solution {
public:
    std::string reorganizeString(std::string s)
    {
        auto len{s.size()};

        std::unordered_map<char, size_t> charCountMap{};
        for (auto c : s) {
            ++charCountMap[c];
            if (charCountMap[c] > (len + 1) / 2) {
                return "";
            }
        }

        std::vector<std::pair<char, size_t>> charCountList{charCountMap.begin(), charCountMap.end()};
        std::sort(charCountList.begin(), charCountList.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });

        std::string sortedString{};
        for (auto [c, count] : charCountList) {
            sortedString.append(count, c);
        }

        std::string res{};
        for (auto i{0UL}, j{(len - 1) / 2 + 1}; i <= (len - 1) / 2; ++i, ++j) {
            res.push_back(sortedString[i]);
            if (j < len) {
                res.push_back(sortedString[j]);
            }
        }

        return res;
    }

    std::string sortCharByCount(const std::string& s)
    {
        std::unordered_map<char, size_t> charCountMap{};
        for (auto c : s) {
            ++charCountMap[c];
        }

        std::vector<std::pair<char, size_t>> charCountList{charCountMap.begin(), charCountMap.end()};
        std::sort(charCountList.begin(), charCountList.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });

        std::string sortedString{};
        for (auto [c, count] : charCountList) {
            sortedString.append(count, c);
        }

        return sortedString;
    }
};

TEST(A, A)
{
    EXPECT_EQ(Solution().sortCharByCount("cczzzdaaaajjjjj"), "jjjjjaaaazzzccd");
    EXPECT_EQ(Solution().sortCharByCount("a"), "a");
    EXPECT_EQ(Solution().sortCharByCount(""), "");
}
