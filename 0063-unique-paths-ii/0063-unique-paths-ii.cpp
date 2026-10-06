class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        vector<long long> dp(n, 0);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (auto& row : obstacleGrid) {
            for (int c = 0; c < n; c++) {
                if (row[c] == 1) dp[c] = 0;
                else if (c > 0) dp[c] += dp[c - 1];
            }
        }
        return (int)dp[n - 1];
    }
};