class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (dfs(board, word, r, c, 0)) return true;
        return false;
    }

private:
    int m, n;
    bool dfs(vector<vector<char>>& b, const string& w, int r, int c, int k) {
        if (r < 0 || r >= m || c < 0 || c >= n || b[r][c] != w[k]) return false;
        if (k == (int)w.size() - 1) return true;
        char tmp = b[r][c];
        b[r][c] = '#';
        bool found = dfs(b, w, r + 1, c, k + 1) || dfs(b, w, r - 1, c, k + 1) ||
                     dfs(b, w, r, c + 1, k + 1) || dfs(b, w, r, c - 1, k + 1);
        b[r][c] = tmp;
        return found;
    }
};