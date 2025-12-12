/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min-heap comparing node values
        priority_queue<ListNode*, vector<ListNode*>, 
            function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        // Push first node of each list
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        // Build the merged list
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};
