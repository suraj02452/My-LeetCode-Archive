class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                pal[i][j] = s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]);

        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, pal, path, res);
        return res;
    }

private:
    void backtrack(const string& s, int start, const vector<vector<bool>>& pal,
                   vector<string>& path, vector<vector<string>>& res) {
        if (start == (int)s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); end++) {
            if (!pal[start][end]) continue;
            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, pal, path, res);
            path.pop_back();
        }
    }
};