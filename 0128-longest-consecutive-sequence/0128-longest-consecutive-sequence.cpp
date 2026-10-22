class Solution {
    unordered_map<int, int> parent, sz;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];     // path halving
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        for (int x : nums) { parent[x] = x; sz[x] = 1; }
        for (auto& [x, _] : parent)
            if (parent.count(x + 1)) unite(x, x + 1);

        int best = 0;
        for (auto& [x, _] : parent)
            if (find(x) == x) best = max(best, sz[x]);
        return best;
    }
};