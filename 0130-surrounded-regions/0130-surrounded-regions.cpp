class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        auto mark = [&](int r, int c) {
            stack<pair<int,int>> st;
            st.push({r, c});
            board[r][c] = 'S';
            int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
            while (!st.empty()) {
                auto [cr, cc] = st.top(); st.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = cr + dr[d], nc = cc + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                        board[nr][nc] = 'S';
                        st.push({nr, nc});
                    }
                }
            }
        };

        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O') mark(r, 0);
            if (board[r][n - 1] == 'O') mark(r, n - 1);
        }
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O') mark(0, c);
            if (board[m - 1][c] == 'O') mark(m - 1, c);
        }

        for (auto& row : board)
            for (char& ch : row)
                ch = (ch == 'O') ? 'X' : (ch == 'S') ? 'O' : ch;
    }
};