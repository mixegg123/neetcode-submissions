class Solution {
public:
    int min_left;
    int max_len;
    string longestPalindrome(string s) {
        //condition 2N-1

        int n = s.size();
        min_left = 0;
        max_len = 1;
        for(int i = 0; i<n; i++)
        {
            count(s, i, i);
            count(s, i, i+1);
        }
        return s.substr(min_left, max_len);
    }
private:

    void count(string &s, int l, int r)
    {
        while(l>=0&&r<s.size()&&s[l]==s[r])
        {
            if(max_len < r-l+1)
            {
                min_left = l;
                max_len = r-l+1;
            }
            l--;
            r++;
        }
    }
};
