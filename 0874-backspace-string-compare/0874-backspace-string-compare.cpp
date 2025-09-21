class Solution {
public:

    string buildString(string str)
    {
        stack<char> st;
        for(char c : str)
        {
            if(c != '#')
            {
                st.push(c);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        string result;

        while(!st.empty())
        {
            result = result + st.top();
            st.pop();
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};