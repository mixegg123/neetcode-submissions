class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, "", 0, 0, ans);
        return ans;
    }

    void dfs(int n, string tmp, int l, int r, vector<string> & ans)
    {
    
        if(tmp.size() == 2*n)
        {
            //if(isValidPar(tmp))
                ans.push_back(tmp);
            return;
        }
        //executing

        //recursive
        if(l<n) dfs(n, tmp+"(", l+1, r, ans);
        //recursive
        if(l>r) dfs(n, tmp+")", l, r+1, ans);
    }

    bool isValidPar(string s)
    {
        int valid = 0;

        for(auto &c : s)
        {
            if(c == '(') valid++;
            else valid --;

            if(valid < 0)
                return false;
        }
        return valid == 0;
    }
};
