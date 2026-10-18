class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;

        string digits;
        for (int d = 1; d <= n; d++) digits += char('0' + d);

        k--;                                     // 0-based
        string res;
        for (int remaining = n; remaining >= 1; remaining--) {
            int block = fact[remaining - 1];
            int idx = k / block;
            k %= block;
            res += digits[idx];
            digits.erase(digits.begin() + idx);
        }
        return res;
    }
};