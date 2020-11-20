#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    std::string CombineChars(std::string input, int k)
    {
        if (input.size() <= 1) {
            return input;
        }
        if (k <= 1) {
            return input;
        }

        interval = k;

        std::map<char, size_t> myMap{};
        for (auto c : input) {
            ++myMap[c];
        }

        std::vector<std::pair<char, size_t>> myArr{myMap.begin(), myMap.end()};

        std::sort(myArr.begin(), myArr.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });

        input.clear();
        for (auto [c, count] : myArr) {
            input.append(count, c);
        }

        curr.resize(input.size(), 0);

        bt(input, 0, 0, 0);

        return res;
    }

    void bt(const std::string& s, size_t index, size_t startPos, char pre)
    {
        if (index == s.size()) {
            success = true;
            res = curr;
            return;
        }

        if (s[index] != pre) {
            startPos = 0;
        }

        for (auto i{startPos}; i < curr.size() && !success; ++i) {
            if (curr[i] == 0) {
                curr[i] = s[index];

                bt(s, index + 1, i + interval, s[index]);

                curr[i] = 0;
            }
        }
    }

private:
    std::string curr{};
    std::string res{};
    size_t interval{};
    bool success{false};
};

TEST(SolutionTest, Test)
{
    auto input{"zzzbbbaa"};

    EXPECT_EQ(Solution().CombineChars(input, 2), "axaxayxy");

    EXPECT_EQ(Solution().CombineChars("", 2), "");

    EXPECT_EQ(Solution().CombineChars("a", 43), "a");
}
