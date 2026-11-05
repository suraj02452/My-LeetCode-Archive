class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a = parse(version1), b = parse(version2);
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int x = i < (int)a.size() ? a[i] : 0;
            int y = i < (int)b.size() ? b[i] : 0;
            if (x != y) return x < y ? -1 : 1;
        }
        return 0;
    }

private:
    vector<int> parse(const string& v) {
        vector<int> parts;
        stringstream ss(v);
        string token;
        while (getline(ss, token, '.')) parts.push_back(stoi(token));
        return parts;
    }
};