class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);
        vector<string> words;
        string w;
        while (in >> w) words.push_back(w);      // >> skips any amount of whitespace

        string res;
        for (int i = (int)words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i > 0) res += ' ';
        }
        return res;
    }
};