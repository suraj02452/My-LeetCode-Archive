class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int maximum = 0;

        for (int value : arr) {
            maximum = min(value, maximum + 1);
        }

        return maximum;
    }
};