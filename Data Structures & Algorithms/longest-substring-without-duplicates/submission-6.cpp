class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int nums[26] = {0};
        unordered_map<char, int> m; //<char, index>
        int l = 0, ans = 0;
        for(int r = 0;r<s.size(); r++)
        {
            if(m.find(s[r]) != m.end())
                l = max(l, m[s[r]]+1);
            m[s[r]] = r;
            //printf("r:%d, l:%d, s[%d]:%c\n",r, l, r, s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
