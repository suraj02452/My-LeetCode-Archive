class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Apply limits coming from the left.
        for (int i = 1; i < m; ++i) {
            int distance = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + distance
            );
        }

        // Apply limits coming from the right.
        for (int i = m - 2; i >= 0; --i) {
            int distance = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + distance
            );
        }

        long long answer = 0;

        for (int i = 1; i < m; ++i) {
            long long distance =
                restrictions[i][0] - restrictions[i - 1][0];
            long long leftHeight = restrictions[i - 1][1];
            long long rightHeight = restrictions[i][1];

            long long peak =
                (leftHeight + rightHeight + distance) / 2;

            answer = max(answer, peak);
        }

        // After the last restriction, heights can increase by 1 per building.
        answer = max(
            answer,
            (long long)restrictions.back()[1]
                + n - restrictions.back()[0]
        );

        return static_cast<int>(answer);
    }
};