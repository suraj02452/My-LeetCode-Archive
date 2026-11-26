#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        long long MOD1 = 1e9 + 7, BASE1 = 1315423911;
        long long MOD2 = 1e9 + 9, BASE2 = 2654435761;
        
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
        
        auto hasUnique = [&](int len) {
            unordered_map<unsigned long long, int> counts;
            counts.reserve(n - len + 1);
            for (int i = 0; i <= n - len; ++i) {
                long long sub1 = (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;
                long long sub2 = (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;
                unsigned long long key = ((unsigned long long)sub1 << 32) | sub2;
                counts[key]++;
            }
            for (auto& [k, v] : counts) {
                if (v == 1) return true;
            }
            return false;
        };
        
        int left = 1, right = n, ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
