class Solution {
    unordered_map<int, int> idx;
    int post;

    TreeNode* build(const vector<int>& postorder, int lo, int hi) {
        if (lo > hi) return nullptr;
        int rootVal = postorder[post--];
        int mid = idx[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->right = build(postorder, mid + 1, hi);
        root->left = build(postorder, lo, mid - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
        post = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};   
    