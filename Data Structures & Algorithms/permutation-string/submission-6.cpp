class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);

        for(const char c : s1)
            count[c-'a']++;

        for(int i = 0 ; i<s2.size() - s1.size() + 1 ; i++)
        {
            int len = 0;
            vector<int> tmp = count;
            for(int j = i; j<i+s1.size();j++)
            {
                if(--tmp[s2[j]-'a'] >= 0)
                    len++;
            }
            if(len == s1.size())
                return true;
        }
        return false;
    }
};
