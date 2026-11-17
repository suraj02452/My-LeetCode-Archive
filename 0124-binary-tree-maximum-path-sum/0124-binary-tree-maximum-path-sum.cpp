class Solution {
    int best;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // A complete path can use both branches.
        best = max(best, node->val + left + right);

        // A path extended by the parent can use only one branch.
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        dfs(root);
        return best;
    }
};