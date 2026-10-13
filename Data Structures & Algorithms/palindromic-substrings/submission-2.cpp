class Solution {
public:
    int countSubstrings(string s) {
        //2D DP 解,dp[i][j] 表示 s[i..j] 是否為回文
        //dp[X][X] = true;
        //長度 n 的字串,中心總共有 n + (n-1) = 2n - 1 個。
        int n = s.size();
#if 0//2D DP
    //not necessary.. maybe
#else
        int ans = 0;
        for(int i = 0; i< n;i++)
        {
            int cnt = (count(s, i, i) + count(s, i, i+1));
            ans += cnt;
        }
        return ans;
#endif
    }

    int count(string s, int l, int r)
    {
        int cnt = 0;
        while(l<=r && l>=0 && r< s.size())
        {
            if(l==r)
                cnt++;
            else
            {
                if(s[l] == s[r])
                    cnt++;
                else
                    break;
            }
            l--;r++;
        }
        return cnt;
    }
};
