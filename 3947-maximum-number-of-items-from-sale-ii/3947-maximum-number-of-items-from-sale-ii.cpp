class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> frequency(n + 1, 0);
        vector<int> gain(n + 1, 0);

        for (const auto& item : items) {
            ++frequency[item[0]];
        }

        // Count eligible free-item types for each factor.
        for (int factor = 1; factor <= n; ++factor) {
            for (int multiple = factor; multiple <= n;
                 multiple += factor) {
                gain[factor] += frequency[multiple];
            }
            --gain[factor]; // Exclude the purchased item itself.
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long cheapest = items[0][1];
        long long remaining = budget;
        long long answer = 0;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (price > 2 * cheapest) break;
            if (price > remaining) break;

            long long buy = min(
                static_cast<long long>(gain[factor]),
                remaining / price
            );

            answer += 2 * buy;
            remaining -= buy * price;
        }

        answer += remaining / cheapest;
        return static_cast<int>(answer);
    }
};

