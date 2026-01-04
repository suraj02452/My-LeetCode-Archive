class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], temp, ans); // reuse allowed
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};
