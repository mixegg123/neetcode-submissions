class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //map, for r, and l
        int size_s1 = s1.size();
        int size_s2 = s2.size();
        unordered_map<char ,int> m;
        if(size_s1 > size_s2) return false;

        int l = 0;
        for(const char c : s1)
            m[c]++;

        for(int r = size_s1;r<=size_s2;r++)
        {
            int len = r-l;
            unordered_map<char, int> tmp = m;
            for(int j = l; j<r; j++)
            {
                if(tmp.find(s2[j]) != tmp.end())
                {
                    tmp[s2[j]]--;
                    if(tmp[s2[j]] == 0)
                        tmp.erase(s2[j]);
                } 
            }
            if(tmp.empty())
                return true;

            l++;
        }
        return false;
    }
};
