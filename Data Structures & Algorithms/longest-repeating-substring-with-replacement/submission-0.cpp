class Solution {
public:
    int characterReplacement(string s, int k) {
        // I read alot hint
        vector<int> words(26, 0);
        //words[s[r] - 'A']++;
        //words[s[l] - 'A']--;
        int maxLen = 0, l = 0, r = 0, res = 0;
        for(r = 0; r<s.size(); r++)
        {
            words[s[r] - 'A']++;
            maxLen = max(maxLen, words[s[r]-'A']);
            //你可以把這個舊的 maxLen 當成一個「高懸的紀錄門檻」：沒人打破門檻時，大家平移過場；有人打破門檻時，門檻與視窗同步升級。
            //(r-l+1) - maxLen > k;
            if((maxLen + k) < (r-l+1))
            {
                words[s[l] - 'A']--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
