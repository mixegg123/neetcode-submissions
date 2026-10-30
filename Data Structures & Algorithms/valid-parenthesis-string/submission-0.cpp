class Solution {
public:
    bool checkValidString(string s) {
        //two-stack solution, good idea
        stack<pair<char,int>> lst;
        stack<pair<char,int>> sst;
        //l only keep left parenthesis
        //* for * but we add
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
                lst.push({'(', i});
            if(s[i] == '*')
                sst.push({'*', i});
            if(s[i] == ')')
            {
                if(!lst.empty())
                    lst.pop();
                else if(!sst.empty())
                    sst.pop();
                else 
                    return false;
            }
        }

        while(!lst.empty() && !sst.empty())
        {
            if(lst.top().second < sst.top().second)
            {
                lst.pop();
                sst.pop();
            }
            else 
                return false;
        }
        return lst.empty();
    }
};
