#include "header.h"

class Solution {
public:
    int result{0};
    int pathSum3(TreeNode* root, int sum)
    {
        std::map<int, int> preSum{0, 1};
        std::vector<TreeNode*> s{root};

        auto currSum = 0;
        while (!s.empty()) {
            auto* curr = s.back();
            s.pop_back();

            currSum += curr->val;
            if (preSum.count(currSum - sum) != 0) {
                result += preSum.at(currSum - sum);
            }

            if (preSum.count(currSum) == 0) {
                preSum.emplace(currSum, 1);
            }
            else {
                preSum.at(currSum) += 1;
            }

            if (curr->left != nullptr) {
                s.push_back(curr->left);
            }

            if (curr->right != nullptr) {
                s.push_back(curr->right);
            }
        }
    }

    int pathSum2(TreeNode* root, int sum)
    {
        std::map<int, int> preSum{0, 1};
        helper(root, 0, sum, preSum);
        return result;
    }

    void helper(TreeNode* node, int currSum, int target, std::map<int, int>& preSum)
    {
        if (node == nullptr) {
            return;
        }

        currSum += node->val;
        if (preSum.count(currSum - target) != 0U) {
            result += preSum.at(currSum - target);
        }

        if (preSum.count(currSum) == 0) {
            preSum.emplace(currSum, 1);
        }
        else {
            preSum.at(currSum) += 1;
        }

        helper(node->left, currSum, target, preSum);
        helper(node->right, currSum, target, preSum);

        preSum.at(currSum) -= 1;
    }

    int pathSum(TreeNode* root, int sum)
    {
        if (root == nullptr) {
            return 0;
        }

        checkSum(root, 0, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);

        return result;
    }

    void checkSum(TreeNode* node, int total, int sum)
    {
        if (node == nullptr) {
            return;
        }

        if (node->val + total == sum) {
            ++result;
        }

        checkSum(node->left, node->val + total, sum);
        checkSum(node->right, node->val + total, sum);
    }

    void checkSum2(TreeNode* node, int sum)
    {
        if (node == nullptr) {
            return;
        }

        std::vector<std::pair<TreeNode*, int>> s{{node, 0}};
        while (!s.empty()) {
            auto [node, total] = s.back();
            s.pop_back();

            if (total + node->val == sum) {
                ++result;
            }

            if (node->right != nullptr) {
                s.emplace_back(node->right, total + node->val);
            }
            if (node->left != nullptr) {
                s.emplace_back(node->left, total + node->val);
            }
        }
    }
};