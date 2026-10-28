class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0);

        int lo = prices[0];
        for (int i = 1; i < n; i++) {
            lo = min(lo, prices[i]);
            left[i] = max(left[i - 1], prices[i] - lo);
        }

        int hi = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            hi = max(hi, prices[i]);
            right[i] = max(right[i + 1], hi - prices[i]);
        }

        int best = 0;
        for (int i = 0; i < n; i++)
            best = max(best, left[i] + right[i]);
        return best;
    }
};