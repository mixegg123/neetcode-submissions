class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //backtrace
        vector<string> dp, ans;
        if(digits.empty())
            return ans;
        for( char c : digits)
        {
            if(c == '2')
                dp.push_back("abc");
            if(c == '3')
                dp.push_back("def");
            if(c == '4')
                dp.push_back("ghi");
            if(c == '5')
                dp.push_back("jkl");
            if(c == '6')
                dp.push_back("mno");
            if(c == '7')
                dp.push_back("pqrs");
            if(c == '8')
                dp.push_back("tuv");
            if(c == '9')
                dp.push_back("wxyz");
        }
        dfs(dp, 0, "", ans);

        return ans;
    }

    void dfs(vector<string> &dp, int start, string tmp, vector<string> &ans)
    {
        if(start >= dp.size())
        {
            ans.push_back(tmp);
            return;
        }

        for(int i = 0;i<dp[start].size();i++)
        {
            dfs(dp,start+1, tmp + dp[start][i],ans);
        }
    }
};
