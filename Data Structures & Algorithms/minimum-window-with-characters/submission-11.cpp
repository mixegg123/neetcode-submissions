class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        unordered_map<char, int> m;
        for(char c : t)
            m[c]++;
//Failing case: s = "aab",t = "ab" → 應該是 "ab",你的會回傳 "aab"
/*
m[c] 的值	意思
> 0	還欠,視窗裡 c 不夠
= 0	剛好夠
< 0	多了,視窗裡 c 比需要的還多
*/
        int cnt = 0, len = INT_MAX, l = 0, start = 0;
        string ans = "";
        for(int r = 0;r<s.size();r++)
        {
            m[s[r]]--;

            if(m[s[r]] >= 0)
                cnt++;
            while(cnt == t.size())
            {
                if(len > r-l+1)
                {          
                    len = r-l+1;
                    start = l;
                }
                if(++m[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return len == INT_MAX?"":s.substr(start, len);
    }
};
