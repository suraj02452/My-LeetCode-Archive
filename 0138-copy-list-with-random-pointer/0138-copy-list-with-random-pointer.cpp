class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        m[nullptr] = nullptr;

        for (Node* c = head; c; c = c->next)
            m[c] = new Node(c->val);

        for (Node* c = head; c; c = c->next) {
            m[c]->next = m[c->next];
            m[c]->random = m[c->random];
        }
        return m[head];
    }
};