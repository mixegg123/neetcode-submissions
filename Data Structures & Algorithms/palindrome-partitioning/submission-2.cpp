class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> tmp;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        dfs(s, 0, tmp, ans, visited);
        return ans;
    }
/*
                     start=0
          ┌────────────┼─────────────┐
       切 "a"        切 "aa"       切 "aab"
       ✓回文         ✓回文          ✗ 不是回文,剪掉
          │             │
       start=1       start=2
       ┌───┴───┐        │
    切 "a"   切 "ab"  切 "b"
    ✓        ✗剪掉    ✓
       │                │
    start=2          start=3 → 收答案 ["aa","b"]
       │
    切 "b" ✓
       │
    start=3 → 收答案 ["a","a","b"]
*/
    void dfs(string &s, int start, vector<string> &tmp, 
    vector<vector<string>> &ans, vector<vector<bool>> &v)
    {
        //base condtion
        int n = s.size();
        if(start == n)
        {
            ans.push_back(tmp);
            //printf("ans update!\n");
            return;
        }

        for(int i = start; i<n; i++)
        {
            if(v[start][i] || isPar(s, start ,i))
            {
                v[start][i] = true;
                tmp.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, tmp, ans, v);
                tmp.pop_back();
            }
        }
    }

    bool isPar(string &s, int l, int r)
    {
        while(l<r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
