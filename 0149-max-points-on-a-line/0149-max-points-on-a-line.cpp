class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int best = 1;
        for (int i = 0; i < n; i++) {
            if (best >= n - i) break;            // can't beat best with the points left
            unordered_map<long long, int> slopes;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                long long key = (long long)dy * 100000 + dx;   // dx in [0, 20000], so the key is unique
                best = max(best, ++slopes[key] + 1);
            }
        }
        return best;
    }
};