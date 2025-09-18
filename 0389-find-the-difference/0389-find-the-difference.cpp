class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for(char ch : s)
        {
            result = result ^ ch;
        }

        for(char ch : t)
        {
            result = result ^ ch;
        }

        return result;
    }
};