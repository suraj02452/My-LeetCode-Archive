class Solution {
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& a, const Matrix& b) {
        int m = a.size();
        Matrix c(m, vector<long long>(m, 0));

        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < m; ++k) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < m; ++j) {
                    c[i][j] =
                        (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }

    vector<long long> multiplyVector(
        const Matrix& a, const vector<long long>& v
    ) {
        int m = a.size();
        vector<long long> result(m, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i] =
                    (result[i] + a[i][j] * v[j]) % MOD;
            }
        }

        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        Matrix transition(m, vector<long long>(m, 0));

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < x; ++y) {
                transition[x][m - 1 - y] = 1;
            }
        }

        // Length 2: x choices for a smaller preceding value.
        vector<long long> up(m);
        for (int x = 0; x < m; ++x) {
            up[x] = x;
        }

        int power = n - 2;

        while (power > 0) {
            if (power & 1) {
                up = multiplyVector(transition, up);
            }

            power >>= 1;
            if (power > 0) {
                transition = multiply(transition, transition);
            }
        }

        long long answer = 0;
        for (long long count : up) {
            answer = (answer + count) % MOD;
        }

        // Reflection gives equally many downward-ending arrays.
        return static_cast<int>(2 * answer % MOD);
    }
};