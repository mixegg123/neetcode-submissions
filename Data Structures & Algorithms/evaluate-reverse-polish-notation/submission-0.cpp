class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &s : tokens)
        {
            if(s=="+"||s=="-"||s=="*"||s=="/") {
                //num1 , nums2
                int num2 = st.top();st.pop();
                int num1 = st.top();st.pop();
                int res = 0;
                if(s=="+")
                    res = num1+num2;
                if(s=="-")
                    res = num1-num2;
                if(s=="*")
                    res = num1*num2;
                if(s=="/")
                    res = num1/num2;
                st.push(res);
            } else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
