class Solution {
public:
    Node* connect(Node* root) {
        Node* leftmost = root;
        while (leftmost && leftmost->left) {
            for (Node* node = leftmost; node; node = node->next) {
                node->left->next = node->right;
                if (node->next) node->right->next = node->next->left;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};