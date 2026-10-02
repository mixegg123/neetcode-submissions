class Solution {
public:
    vector<int> partitionLabels(string s) {
#if 1//my solution
    //hasp map to record cnt
    //while find cnt-- and erase it, finish while cnt reach to zero
    unordered_map<char, int> m;
    vector<int> res;
    int l = 0;
    int cnt = 0;
    for(const char c : s)
        m[c]++;
    
    for(int r = 0; r<s.size(); r++)
    {
        if(m.find(s[r]) != m.end())
        {
            m[s[r]]--;
            cnt += (m[s[r]]);
            m.erase(s[r]);
        } else
        {
            cnt--;
        }
        //printf("r:%d,l:%d,s[r]:%c,cnt:%d\n", r, l, s[r], cnt);
        if(cnt == 0)
        {
            res.push_back(r-l+1);
            l = r+1;
        }
    }
    return res;
#else// from hint

#endif
    }
};
