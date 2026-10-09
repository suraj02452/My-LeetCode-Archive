class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n), diag(2 * n), anti(2 * n);
        return backtrack(0, n, cols, diag, anti);
    }

private:
    int backtrack(int r, int n, vector<bool>& cols, vector<bool>& diag, vector<bool>& anti) {
        if (r == n) return 1;
        int count = 0;
        for (int c = 0; c < n; c++) {
            int d = r - c + n;                  // shift to keep the index ≥ 0
            if (cols[c] || diag[d] || anti[r + c]) continue;
            cols[c] = diag[d] = anti[r + c] = true;
            count += backtrack(r + 1, n, cols, diag, anti);
            cols[c] = diag[d] = anti[r + c] = false;
        }
        return count;
    }
};