class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool valid(TreeNode* node, long long low, long long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        return valid(node->left, low, node->val) &&
               valid(node->right, node->val, high);
    }
};