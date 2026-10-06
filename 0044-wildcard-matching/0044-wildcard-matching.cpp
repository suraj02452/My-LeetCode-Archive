class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), cur(n + 1);
        prev[0] = true;
        for (int j = 1; j <= n; j++)
            prev[j] = prev[j - 1] && p[j - 1] == '*';

        for (int i = 1; i <= m; i++) {
            cur[0] = false;
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*')
                    cur[j] = cur[j - 1] || prev[j];
                else
                    cur[j] = (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && prev[j - 1];
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};