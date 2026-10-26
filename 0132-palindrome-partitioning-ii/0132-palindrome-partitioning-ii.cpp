class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> cuts(n);

        for (int j = 0; j < n; j++) {
            int best = j;
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                    best = (i == 0) ? 0 : min(best, cuts[i - 1] + 1);
                }
            }
            cuts[j] = best;
        }
        return cuts[n - 1];
    }
};