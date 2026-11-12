
class Solution {
public:
    int dp[31][31][31];

    bool solve(string &s1, string &s2, int i, int j, int len) {

        // Both substrings are equal
        if (s1.substr(i, len) == s2.substr(j, len))
            return true;

        // Check if already calculated
        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        // Check character frequencies
        int freq[26] = {0};

        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }

        for (int k = 0; k < 26; k++) {
            if (freq[k] != 0)
                return dp[i][j][len] = false;
        }

        // Try every possible split
        for (int k = 1; k < len; k++) {

            // Case 1: No swapping
            bool noSwap =
                solve(s1, s2, i, j, k) &&
                solve(s1, s2, i + k, j + k, len - k);

            if (noSwap)
                return dp[i][j][len] = true;

            // Case 2: Swapping
            bool swap =
                solve(s1, s2, i, j + len - k, k) &&
                solve(s1, s2, i + k, j, len - k);

            if (swap)
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        int n = s1.size();

        if (n != s2.size())
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0, n);
    }
};
