class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Step 1: sort array
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2]; // initial sum

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // If this sum is closer to target, update closestSum
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }

            // Move pointers based on comparison
            if (currentSum < target)
                left++;
            else if (currentSum > target)
                right--;
            else
                return currentSum; // Exact match found
        }
    }

    return closestSum;
    }
};