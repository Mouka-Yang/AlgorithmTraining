#include "header.h"

#include <string>

class Codec {
public:
    std::string serialize(TreeNode* root)
    {
        std::string result{};
        std::vector<TreeNode*> s{root};

        while (!s.empty()) {
            auto* curr = s.back();
            s.pop_back();

            result.append(std::to_string(curr->val) + "#");

            if (curr->right != nullptr) {
                s.push_back(curr->right);
            }
            if (curr->left != nullptr) {
                s.push_back(curr->left);
            }
        }

        result.erase(result.end() - 1);
        return result;
    }

    TreeNode* deserialize(std::string data)
    {
        std::vector<int> preorder{};
        auto done = false;
        for (auto it = 0U; !done;) {
            auto nodeEnd = data.find('#', it);
            if (nodeEnd == std::string::npos) {
                done = true;
            }

            preorder.push_back(std::stoi(data.substr(it, nodeEnd)));
            it = nodeEnd + 1;
        }

        if (preorder.empty()) {
            return nullptr;
        }
        auto* root = new TreeNode(preorder[0]);
        std::vector<TreeNode*> s{root};
        for (auto i = 1U; i < preorder.size(); ++i) {
            auto* curr = new TreeNode(preorder[i]);
            if (preorder[i] < s.back()->val) {
                s.back()->left = curr;
            }
            else {
                TreeNode* parent = nullptr;
                while (!s.empty() && s.back()->val < preorder[i]) {
                    parent = s.back();
                    s.pop_back();
                }
                parent->right = curr;
            }
            s.push_back(curr);
        }

        return root;
    }
};