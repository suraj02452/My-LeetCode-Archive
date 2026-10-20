class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;

        for (int k = 1; k < n; k++) {
            int n2 = ugly[i2] * 2, n3 = ugly[i3] * 3, n5 = ugly[i5] * 5;
            ugly[k] = min({n2, n3, n5});
            if (ugly[k] == n2) i2++;
            if (ugly[k] == n3) i3++;
            if (ugly[k] == n5) i5++;
        }
        return ugly[n - 1];
    }
};