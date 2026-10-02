class Solution {
public:
    vector<int> partitionLabels(string s) {
#if 1//my solution
    //hasp map to record cnt
    //while find cnt-- and erase it, finish while cnt reach to zero
    //<character, last index>
    unordered_map<char, int> m;
    vector<int> res;
    int l = 0, end = 0;
    for(int i = 0; i<s.size(); i++)
        //change to store last index
        m[s[i]] = i;
    
    for(int r = 0; r<s.size(); r++)
    {
        end = max(end, m[s[r]]);

        if(end == r)
        {
            res.push_back(r-l+1);
            l = r+1;
            end = 0;
        }
    }
    return res;
#else// from hint
    i am bingo same soluition :)
#endif
    }
};
