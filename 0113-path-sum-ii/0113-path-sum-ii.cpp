class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int remaining, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        path.push_back(node->val);
        remaining -= node->val;
        if (!node->left && !node->right && remaining == 0)
            res.push_back(path);                    // push_back copies the vector
        else {
            dfs(node->left, remaining, path, res);
            dfs(node->right, remaining, path, res);
        }
        path.pop_back();
    }
};