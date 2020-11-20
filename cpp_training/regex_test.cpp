#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <regex>
#include <string>
#include <vector>
using namespace testing;

class RegexTest : public Test {
public:
    void SetUp() override {}
    void TearDown() override {}
    std::vector<std::string> filenames{"foo.txt", "bar.txt", "baz.dat", "aabbcc"};
};

TEST_F(RegexTest, Test)
{
    std::regex basenameRegex{".+\\..+"};

    EXPECT_TRUE(std::regex_match(filenames[0], basenameRegex));
    EXPECT_TRUE(std::regex_match(filenames[1], basenameRegex));
    EXPECT_TRUE(std::regex_match(filenames[2], basenameRegex));
    EXPECT_FALSE(std::regex_match(filenames[3], basenameRegex));

    std::regex baseGroupRegex{"(.+)\\..+"};
    std::smatch baseMatchResult{};
    EXPECT_TRUE(std::regex_match(filenames[0], baseMatchResult, baseGroupRegex));
    EXPECT_EQ(baseMatchResult[0].str(), filenames[0]);
    EXPECT_EQ(baseMatchResult[1].str(), "foo");

    std::regex fileGroupRegex("(.+)\\.(.+)");
    std::smatch fileMatchResult{};
    EXPECT_TRUE(std::regex_match(filenames[0], fileMatchResult, fileGroupRegex));
    EXPECT_EQ(fileMatchResult[0], filenames[0]);
    EXPECT_EQ(fileMatchResult[1], "foo");
    EXPECT_EQ(fileMatchResult[2], "txt");
}
