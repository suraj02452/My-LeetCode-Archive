class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
private:
    void dfs(TreeNode* node, vector<int>& res) {
        if (!node) return;
        dfs(node->left, res);
        dfs(node->right, res);
        res.push_back(node->val);
    }
};