class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 1, 0);

        int prefix = n; // Offset representing prefix sum 0.
        freq[prefix] = 1;

        long long smaller = 0;
        long long answer = 0;

        for (int value : nums) {
            if (value == target) {
                smaller += freq[prefix];
                ++prefix;
            } else {
                --prefix;
                smaller -= freq[prefix];
            }

            answer += smaller;
            ++freq[prefix];
        }

        return answer;
    }
};