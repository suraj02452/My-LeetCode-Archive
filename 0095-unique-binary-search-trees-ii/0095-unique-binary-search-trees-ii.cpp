class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

private:
    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};
        vector<TreeNode*> trees;
        for (int rootVal = lo; rootVal <= hi; rootVal++) {
            vector<TreeNode*> lefts = build(lo, rootVal - 1);
            vector<TreeNode*> rights = build(rootVal + 1, hi);
            for (TreeNode* l : lefts)
                for (TreeNode* r : rights)
                    trees.push_back(new TreeNode(rootVal, l, r));
        }
        return trees;
    }
};