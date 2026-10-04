class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, parts;
        backtrack(s, 0, parts, res);
        return res;
    }

private:
    void backtrack(const string& s, int start, vector<string>& parts, vector<string>& res) {
        int leftParts = 4 - parts.size(), leftChars = s.size() - start;
        if (leftParts == 0) {
            if (leftChars == 0)
                res.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            return;
        }
        if (leftChars < leftParts || leftChars > 3 * leftParts) return;

        for (int len = 1; len <= 3 && start + len <= (int)s.size(); len++) {
            string seg = s.substr(start, len);
            if ((len > 1 && seg[0] == '0') || stoi(seg) > 255) break;
            parts.push_back(seg);
            backtrack(s, start + len, parts, res);
            parts.pop_back();
        }
    }
};