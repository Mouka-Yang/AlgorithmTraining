#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

#include "header.h"

class Solution {
public:
    int rob(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        auto [m1, m2] = getSumFromSubtree(root);
        return std::max(m1, m2);
    }

    std::pair<int, int> getSumFromSubtree(TreeNode* node)
    {
        if (node == nullptr) {
            return {0, 0};
        }

        auto [leftMaxNoRoot, leftMaxWithRoot] = getSumFromSubtree(node->left);
        auto [rightMaxNoRoot, rightMaxWithRoot] = getSumFromSubtree(node->right);

        auto maxNoRoot = std::max(
            {leftMaxWithRoot + rightMaxWithRoot, leftMaxNoRoot + rightMaxWithRoot,
             leftMaxWithRoot + rightMaxNoRoot, leftMaxNoRoot + rightMaxNoRoot});
        auto maxWithRoot = leftMaxNoRoot + rightMaxNoRoot + node->val;

        return {maxNoRoot, maxWithRoot};
    }

private:
};

TEST(SolutionTest, Test)
{
    auto root = ConstructTreeFromVector(std::vector<int>({2, 1, 3, MAGIC_INT, 4}));
    EXPECT_EQ(Solution().rob(root), 7);
}
