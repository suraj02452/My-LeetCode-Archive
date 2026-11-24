class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer = 2;

        for (int left = 0; left < n; ++left) {
            int product = 1;

            for (int right = left; right < n; ++right) {
                if (gcd(product, nums[right]) != 1) {
                    break;
                }

                product *= nums[right];
                answer = max(answer, right - left + 1);
            }
        }

        return answer;
    }
};