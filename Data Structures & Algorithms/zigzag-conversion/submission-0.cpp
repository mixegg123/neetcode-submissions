class Solution {
public:
    string convert(string s, int numRows) {
        //0->1->2>(numRos-1 chage to -1)->1->0(0 change to +1) ->1 >2
        if(numRows == 1)
            return s;
        string ans;
        int row = 0, step = 1;
        vector<string> rows(numRows);
        for(int i = 0;i<s.size();i++)
        {
            rows[row]+=s[i];
            row += step;
            if(row == 0)
                step = 1;
            if(row == numRows-1)
                step = -1;
        }

        for(int i = 0;i<rows.size();i++)
        {
            for(const char c:rows[i])
                ans+=c;
        }

        return ans;
    }
};