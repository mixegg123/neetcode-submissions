class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size();
   
        while(l<=r)
        {
            while(!isalpha(s[l]) && !isdigit(s[l]))
                l++;
            while(!isalpha(s[r]) && !isdigit(s[r]))
                r--;
            if((l<=r) && tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
