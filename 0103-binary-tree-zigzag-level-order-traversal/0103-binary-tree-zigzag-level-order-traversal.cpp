class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        stack<TreeNode*> curr, nxt;
        curr.push(root);
        bool leftToRight = true;

        while (!curr.empty()) {
            vector<int> level;
            while (!curr.empty()) {
                TreeNode* node = curr.top(); curr.pop();
                level.push_back(node->val);
                if (leftToRight) {
                    if (node->left)  nxt.push(node->left);
                    if (node->right) nxt.push(node->right);
                } else {
                    if (node->right) nxt.push(node->right);
                    if (node->left)  nxt.push(node->left);
                }
            }
            res.push_back(level);
            swap(curr, nxt);
            leftToRight = !leftToRight;
        }
        return res;
    }
};