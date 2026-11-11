class Solution {
    unordered_set<string> words;
    unordered_map<int, vector<string>> memo;
    string s;
    int maxLen = 0;

    vector<string>& sentences(int i) {
        auto it = memo.find(i);
        if (it != memo.end()) return it->second;

        vector<string> res;
        if (i == (int)s.size()) {
            res.push_back("");
        } else {
            for (int len = 1; len <= maxLen && i + len <= (int)s.size(); len++) {
                string word = s.substr(i, len);
                if (!words.count(word)) continue;
                for (const string& rest : sentences(i + len))
                    res.push_back(rest.empty() ? word : word + " " + rest);
            }
        }
        return memo[i] = move(res);
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        words = unordered_set<string>(wordDict.begin(), wordDict.end());
        for (auto& w : wordDict) maxLen = max(maxLen, (int)w.size());
        return sentences(0);
    }
};