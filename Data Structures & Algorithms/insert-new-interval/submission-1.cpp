class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(!intervals.size())
        {
            ans.push_back(newInterval);
            return ans;
        }
        for(int i = 0; i<intervals.size(); i++)
        {
            //prev.start <= cur.end && prev.end >= cur.start
            //since we already sort: prev.end >= cur.start
            if(newInterval[0] <= intervals[i][1] &&newInterval[1] >= intervals[i][0])
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back(newInterval);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
