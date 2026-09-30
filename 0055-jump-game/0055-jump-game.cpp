class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, last = nums.size() - 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
            if (reach >= last) return true;
        }
        return true;
    }
};