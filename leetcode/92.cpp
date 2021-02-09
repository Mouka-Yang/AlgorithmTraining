#include "header.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        auto halfDistance = (n - m - 1) / 2;

        std::vector<ListNode*> tmp(halfDistance + 1);

        auto curr  = head;
        auto count = 1;
        while (curr != nullptr) {
            if (m <= count && count <= m + halfDistance) {
                tmp.push_back(curr);
            }
            else if (n - halfDistance <= count && count <= n) {
                auto target = tmp.back();
                tmp.pop_back();
                auto tmpValue = target->val;
                target->val   = curr->val;
                curr->val     = tmpValue;
            }
            curr = curr->next;
            count++;
        }
        return head;
    }

    ListNode* reverseBetweenV2(ListNode* head, int m, int n) {
      ListNode preHead{};
      preHead.next = head;

      auto nodeBeforeReverse = &preHead;
      auto nodeStartReverse = head;
      auto reverseLen = n - m + 1;

      while (m-- > 1) {
        nodeBeforeReverse = nodeBeforeReverse->next;
        nodeStartReverse = nodeStartReverse->next;
      }

      auto curr = nodeStartReverse;
      ListNode* preCurr = nullptr;
      while (reverseLen-- > 0) {
        auto tmp = curr->next;
        curr->next = preCurr;

        preCurr = curr;
        curr = tmp;
      }

      nodeBeforeReverse->next = preCurr;
      nodeStartReverse->next = curr;

      return preHead.next;
    }
};

int main()
{
    auto list = ConstructList(std::vector<int>{1, 2, 3, 4, 5, 6});
    Solution().reverseBetween(list, 1, 5);
    PrintList(list);
    DeleteList(list);
}