#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"

#include <algorithm>
using namespace testing;

class Solution {
public:
    size_t getListSize(ListNode* node)
    {
        auto len{0U};

        while (node) {
            node = node->next;
            ++len;
        }

        return len;
    }

    ListNode* sortList(ListNode* head)
    {
        if (!head) {
            return head;
        }

        auto len{getListSize(head)};

        return mergeSort(head, len);
    }

    ListNode* mergeSort(ListNode* node, size_t len)
    {
        if (len <= 1) {
            return node;
        }

        auto nodeBeforeMiddle = findNodeBeforeMiddle(node, len);
        auto middle = nodeBeforeMiddle->next;
        nodeBeforeMiddle->next = nullptr;

        auto left = mergeSort(node, (len + 1) / 2);
        auto right = mergeSort(middle, (len - 1) / 2);

        return mergeSortedLists(left, right);
    }

    ListNode* findNodeBeforeMiddle(ListNode* node, size_t len)
    {
        auto middle{(len - 1) / 2};

        auto res{node};
        auto count{0U};
        while (res && count < middle) {
            res = res->next;
            ++count;
        }

        return res;
    }

    ListNode* mergeSortedLists(ListNode* list1, ListNode* list2)
    {
        auto start2{list2};

        auto head = new ListNode;
        head->next = list1;

        while (start2) {
            auto pre = head;
            auto curr = head->next;
            auto found{false};
            while (curr && !found) {
                if (curr->val < start2->val) {
                    pre = curr;
                    curr = curr->next;
                }
                else {
                    found = true;
                }
            }

            auto tmp = start2;
            start2 = start2->next;

            pre->next = tmp;
            tmp->next = curr;
        }

        auto res{head->next};
        delete head;

        return res;
    }
};

TEST(A, A)
{
    auto head = ConstructList({-1, 5, 3, 4, 0});

    EXPECT_EQ(Solution().sortList(head), nullptr);
}
