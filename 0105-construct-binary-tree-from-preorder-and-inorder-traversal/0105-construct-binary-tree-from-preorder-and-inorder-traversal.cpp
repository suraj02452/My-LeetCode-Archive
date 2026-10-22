class Solution {
    unordered_map<int, int> idx;
    int pre = 0;

    TreeNode* build(const vector<int>& preorder, int lo, int hi) {
        if (lo > hi) return nullptr;
        int rootVal = preorder[pre++];
        int mid = idx[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, lo, mid - 1);
        root->right = build(preorder, mid + 1, hi);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};
 
