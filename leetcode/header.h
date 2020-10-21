#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

ListNode* ConstructList(const std::vector<int> nums)
{
    auto preHead = new ListNode();
    auto curr    = preHead;
    for (auto& num : nums) {
        curr->next = new ListNode(num);
        curr       = curr->next;
    }
    return preHead->next;
}

void PrintList(const ListNode* head)
{
    auto curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void DeleteList(ListNode* head)
{
    auto curr = head;
    while (curr != nullptr) {
        auto tmp = curr;
        curr     = curr->next;
        delete tmp;
    }
}

constexpr int MAGIC_INT = 19950813;

TreeNode* getTreeNode(const std::vector<int>& nums, int count)
{
    if (nums.size() == count) {
        return nullptr;
    }

    return nums[count] == MAGIC_INT ? nullptr : new TreeNode(nums[count]);
}
void addNode(std::deque<TreeNode*>& q, TreeNode* node)
{
    if (node != nullptr) {
        q.push_back(node);
    }
}
TreeNode* ConstructTreeFromVector(const std::vector<int>& nums)
{
    if (nums.size() == 0) {
        return nullptr;
    }

    std::deque<TreeNode*> nodes{};
    auto                  count    = 0;
    auto                  maxCount = nums.size();
    TreeNode*             root     = new TreeNode(nums[count++]);

    addNode(nodes, root);
    while (!nodes.empty() && maxCount != count) {
        auto node = nodes.front();
        nodes.pop_front();
        node->left  = getTreeNode(nums, count++);
        node->right = getTreeNode(nums, count++);
        addNode(nodes, node->left);
        addNode(nodes, node->right);
    }

    return root;
}

void DeleteTree(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    return;
}

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> results{};
    std::vector<int>              currentResult;

    if (root == nullptr)
        return results;
    auto queue = std::deque<TreeNode*>{};
    queue.push_back(root);
    while (!queue.empty()) {
        auto levelNum = queue.size();
        for (int i = 0; i < levelNum; i++) {
            auto node = queue.front();
            queue.pop_front();
            if (node->left != nullptr) {
                queue.push_back(node->left);
            }
            if (node->right != nullptr) {
                queue.push_back(node->right);
            }
            currentResult.push_back(node->val);
        }
        results.push_back(currentResult);
        currentResult.clear();
    }
    return results;
}

bool isLeaf(TreeNode* node)
{
    return node->left == nullptr && node->right == nullptr;
}
std::vector<int> ConstructVectorFromTree(TreeNode* root)
{
    std::vector<int> result{};

    auto queue = std::deque<TreeNode*>{};
    queue.push_back(root);
    while (!queue.empty()) {
        auto node = queue.front();
        auto val  = node == nullptr ? MAGIC_INT : node->val;
        queue.pop_front();
        result.push_back(val);

        if (node != nullptr && !isLeaf(node)) {
            queue.push_back(node->left);
            queue.push_back(node->right);
        }
    }

    return result;
}