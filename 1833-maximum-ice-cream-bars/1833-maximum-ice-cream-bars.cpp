class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> frequency(maxCost + 1, 0);

        for (int cost : costs) {
            ++frequency[cost];
        }

        int answer = 0;

        for (int price = 1; price <= maxCost; ++price) {
            if (price > coins) break;

            int buy = min(frequency[price], coins / price);
            answer += buy;
            coins -= buy * price;
        }

        return answer;
    }
};