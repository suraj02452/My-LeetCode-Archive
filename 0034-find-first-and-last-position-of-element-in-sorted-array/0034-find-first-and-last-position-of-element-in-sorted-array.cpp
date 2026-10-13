class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first == (int)nums.size() || nums[first] != target) return {-1, -1};
        int last = lowerBound(nums, (long long)target + 1) - 1;
        return {first, last};
    }

private:
    int lowerBound(const vector<int>& nums, long long t) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < t) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};