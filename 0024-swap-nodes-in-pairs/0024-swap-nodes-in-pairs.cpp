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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform the swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move prev pointer forward for the next pair
            prev = first;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up to avoid memory leaks
        return newHead;
    }
};