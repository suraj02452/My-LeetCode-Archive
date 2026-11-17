class Solution {
    // Cut off a run of at most size nodes.
    // Return the beginning of the remaining list.
    ListNode* split(ListNode* head, int size) {
        if (!head) return nullptr;

        for (int i = 1; i < size && head->next; ++i) {
            head = head->next;
        }

        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    // Append merged nodes after tail; return the updated tail.
    ListNode* merge(ListNode* a, ListNode* b, ListNode* tail) {
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;

        while (tail->next) {
            tail = tail->next;
        }

        return tail;
    }

public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ++n;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < n; size *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                tail = merge(left, right, tail);
            }
        }

        return dummy.next;
    }
};