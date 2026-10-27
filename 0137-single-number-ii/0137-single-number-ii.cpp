class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t res = 0;
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;
            for (int x : nums)
                count += ((uint32_t)x >> bit) & 1;
            if (count % 3) res |= (1u << bit);
        }
        return (int)res;
    }
};