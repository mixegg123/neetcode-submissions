class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            
            if(st.empty())
                return false;

            if(c == ')')
            {
                if(st.top() != '(')
                    return false;
                st.pop();
            }
            if(c == ']')
            {
                if(st.top() != '[')
                    return false;
                st.pop();
            }
            if(c == '}')
            {
                if(st.top() != '{')
                    return false;
                st.pop();
            }

        }
        return st.empty();
    }
};
