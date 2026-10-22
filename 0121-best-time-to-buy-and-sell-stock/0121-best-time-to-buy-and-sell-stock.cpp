class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], best = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            best = max(best, p - minPrice);
        }
        return best;
    }
};