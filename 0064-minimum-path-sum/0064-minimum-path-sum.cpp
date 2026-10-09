class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int r = 0; r < m; r++) {
            dp[0] += grid[r][0];
            for (int c = 1; c < n; c++)
                dp[c] = grid[r][c] + min(dp[c], dp[c - 1]);
        }
        return dp[n - 1];
    }
};