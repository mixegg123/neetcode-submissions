class Solution {
public:
    int characterReplacement(string s, int k) {
        int word[26] = {0};
        int l = 0, maxLen = 0;
        int ans = 1;
        for(int r = 0;r<s.size();r++)
        {
            word[s[r]-'A']++;

            maxLen = max(maxLen, word[s[r] - 'A']);
            if(maxLen + k < r-l+1)
            {
                word[s[l] -'A']--;
                l++;
            }    
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
