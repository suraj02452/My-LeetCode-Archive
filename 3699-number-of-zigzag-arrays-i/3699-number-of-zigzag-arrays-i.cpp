class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1'000'000'007;
        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m), down(m);
        vector<int> nextUp(m), nextDown(m);

        for (int x = 0; x < m; ++x) {
            up[x] = x;
            down[x] = m - 1 - x;
        }

        for (int len = 3; len <= n; ++len) {
            long long prefix = 0;

            for (int x = 0; x < m; ++x) {
                nextUp[x] = prefix;
                prefix = (prefix + down[x]) % MOD;
            }

            long long suffix = 0;

            for (int x = m - 1; x >= 0; --x) {
                nextDown[x] = suffix;
                suffix = (suffix + up[x]) % MOD;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long answer = 0;
        for (int x = 0; x < m; ++x) {
            answer = (answer + up[x] + down[x]) % MOD;
        }

        return answer;
    }
};