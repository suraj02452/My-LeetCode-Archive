class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double curMax = nums[0], curMin = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            double x = nums[i];
            double a = curMax * x, b = curMin * x;
            curMax = max({x, a, b});
            curMin = min({x, a, b});
            best = max(best, curMax);
        }
        return (int)best;
    }
};