class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++)
        {
            ans += isPali(s, i, i);
            ans += isPali(s, i, i+1);
        }
        return ans;
    }

    int isPali(string s, int l, int r)
    {
        int cnt = 0;
        while(l>=0 && r<s.size() && l <= r && s[l] == s[r])
        {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};
