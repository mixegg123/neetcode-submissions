class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
#if 0
        unordered_set<string> se;
        for(const string word: wordDict)
            se.insert(word);
        int l = 0, len = 0;

        for(int r = 0;r<s.size();r++)
        {
            if(se.find(s.substr(l, r-l+1))!=se.end())
            {
                len += (r-l+1);
                l= (r+1);
            } 
        }

        return len == s.size();
#else
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        //if(i>=word.szie())
        //dp[i] = dp[i] || dp[i-word.size(]//dp[4]?
        for(int i = 1;i<=n;i++)
        {
            for(const string word : wordDict)
            {
                if(i>=word.size())
                {
                    bool match = s.substr(i-word.size(),word.size()) == word;
                    dp[i] = dp[i] || (match && dp[i - word.size()]);
                }
            }
        }
        return dp[n];
#endif
    }
};
