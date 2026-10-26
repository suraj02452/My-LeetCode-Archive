class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        if (lo == hi) return 0;

        int size = max(1, (hi - lo) / (n - 1));
        int count = (hi - lo) / size + 1;
        vector<int> bmin(count, INT_MAX), bmax(count, INT_MIN);

        for (int x : nums) {
            int b = (x - lo) / size;
            bmin[b] = min(bmin[b], x);
            bmax[b] = max(bmax[b], x);
        }

        int best = 0, prevMax = lo;
        for (int b = 0; b < count; b++) {
            if (bmin[b] == INT_MAX) continue;
            best = max(best, bmin[b] - prevMax);
            prevMax = bmax[b];
        }
        return best;
    }
};