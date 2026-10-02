class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for(auto c : s)
            m[c]++;
        for(auto c: t)
        {
            if(m.find(c) != m.end())
            {
                if(--m[c] == 0)
                    m.erase(c);
            } else {
                return false;
            }
        }
        return m.empty();
    }
};
