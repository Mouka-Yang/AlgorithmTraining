struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* preHead = new ListNode(0, head);
        ListNode* pre     = preHead;
        ListNode* curr    = head;
        while (curr != nullptr) {
            while (curr->next != nullptr && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if (pre->next != curr) {
                pre->next = curr->next;
                curr      = curr->next;
            }
            else {
                pre  = pre->next;
                curr = curr->next;
            }
        }
        return preHead->next;
    }
};
