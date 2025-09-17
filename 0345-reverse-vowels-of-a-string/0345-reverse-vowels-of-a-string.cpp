class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int start = 0;
        int end = s.length() - 1;

        while(start < end)
        {
            while(start < end && vowels.find(s[start]) == string::npos)
            {
                start++;
            }

            while(start < end && vowels.find(s[end]) == string::npos)
            {
                end--;
            }

            swap(s[start], s[end]);
            start++;
            end--;
        }

        return s;
    }
};