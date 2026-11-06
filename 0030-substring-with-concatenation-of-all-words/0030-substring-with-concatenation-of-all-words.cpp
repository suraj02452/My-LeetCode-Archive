class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), k = words.size(), L = words[0].size();
        if (n < k * L) return res;

        unordered_map<string, int> need;
        for (auto& w : words) need[w]++;

        for (int off = 0; off < L; off++) {
            unordered_map<string, int> window;
            int left = off, count = 0;

            for (int right = off; right + L <= n; right += L) {
                string w = s.substr(right, L);

                if (!need.count(w)) {              // not a word: restart after it
                    window.clear();
                    count = 0;
                    left = right + L;
                    continue;
                }

                window[w]++;
                count++;
                while (window[w] > need[w]) {      // too many copies: shrink from the left
                    window[s.substr(left, L)]--;
                    count--;
                    left += L;
                }

                if (count == k) {                  // exactly the right words
                    res.push_back(left);
                    window[s.substr(left, L)]--;   // slide forward one word
                    count--;
                    left += L;
                }
            }
        }
        return res;
    }
};