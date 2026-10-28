class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            if (prev->val > curr->val) prev = &dummy;
            while (prev->next && prev->next->val < curr->val)
                prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = nxt;
        }
        return dummy.next;
    }
};