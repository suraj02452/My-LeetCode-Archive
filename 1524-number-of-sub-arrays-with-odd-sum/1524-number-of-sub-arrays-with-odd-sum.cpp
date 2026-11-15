class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        long long even = 1, odd = 0;
        long long answer = 0;
        int parity = 0;

        for (int num : arr) {
            parity ^= (num & 1);

            if (parity == 1) {
                answer = (answer + even) % MOD;
                ++odd;
            } else {
                answer = (answer + odd) % MOD;
                ++even;
            }
        }

        return answer;
    }
};