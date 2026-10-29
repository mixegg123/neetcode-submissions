class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        for(int i = 0; i< n - m + 1; i++)
        {
            int j = 0;
            while(j<m && haystack[i+j] == needle[j])
                j++;

            if(j==m)
                return i;
        }
        return -1;
    }
};