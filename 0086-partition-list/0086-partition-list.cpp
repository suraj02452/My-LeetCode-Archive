class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy, greaterDummy;
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        for (ListNode* curr = head; curr; curr = curr->next) {
            if (curr->val < x) { less->next = curr; less = curr; }
            else               { greater->next = curr; greater = curr; }
        }

        greater->next = nullptr;
        less->next = greaterDummy.next;
        return lessDummy.next;
    }
};