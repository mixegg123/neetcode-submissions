class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int nums[26] = {0};
        unordered_map<char, int> m; //<char, index>
        int l = 0, ans = 0;
        for(int r = 0;r<s.size(); r++)
        {
            //l cannot look back
            if(m.find(s[r]) != m.end())
                l = max(l, m[s[r]]+1);
            m[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
