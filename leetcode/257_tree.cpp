#include "header.h"

#include <sstream>
#include <string>

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> results{};

        std::vector<TreeNode*> s{};
        auto* curr = root;

        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push_back(curr);
                if (curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }

            if (s.back()->left == nullptr && s.back()->right == nullptr) {
                results.push_back(serializePath(s));
            }

            auto* node = s.back();
            s.pop_back();

            if (!s.empty() && s.back()->left == node) {
                curr = s.back()->right;
            }
        }

        return results;
    }

    std::string serializePath(const std::vector<TreeNode*>& path)
    {
        std::stringstream ss;
        auto count = 0U;
        for (const auto* node : path) {
            ss << std::to_string(node->val);
            ++count;
            if (count != path.size()) {
                ss << "->";
            }
        }

        return ss.str();
    }
};