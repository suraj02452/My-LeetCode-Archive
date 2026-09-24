class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, 0, target, path, res);
        return res;
    }

private:
    void backtrack(const vector<int>& c, int start, int remain,
                   vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) {
            if (i > start && c[i] == c[i - 1]) continue;
            if (c[i] > remain) break;
            path.push_back(c[i]);
            backtrack(c, i + 1, remain - c[i], path, res);
            path.pop_back();
        }
    }
};