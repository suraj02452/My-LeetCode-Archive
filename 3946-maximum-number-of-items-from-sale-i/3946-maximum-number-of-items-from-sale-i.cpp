#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAX_FACTOR = 1500;
        vector<int> freq(MAX_FACTOR + 1, 0);
        
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        
        // Precompute free items unlocked for each factor value
        vector<int> free_count(MAX_FACTOR + 1, 0);
        for (int f = 1; f <= MAX_FACTOR; ++f) {
            if (freq[f] > 0) {
                int total_multiples = 0;
                for (int multiple = f; multiple <= MAX_FACTOR; multiple += f) {
                    total_multiples += freq[multiple];
                }
                // Subtract 1 to exclude the item itself (j != i)
                free_count[f] = total_multiples - 1;
            }
        }
        
        vector<int> dp(budget + 1, 0);
        int min_price = INT_MAX;
        
        // Step 1: 0/1 Knapsack for the first copy of each item
        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];
            min_price = min(min_price, price);
            
            if (price <= budget) {
                int val = 1 + free_count[factor];
                for (int w = budget; w >= price; --w) {
                    dp[w] = max(dp[w], dp[w - price] + val);
                }
            }
        }
        
        // Step 2: Unbounded Knapsack for extra copies using the cheapest item
        if (min_price <= budget) {
            for (int w = min_price; w <= budget; ++w) {
                dp[w] = max(dp[w], dp[w - min_price] + 1);
            }
        }
        
        return dp[budget];
    }
};
