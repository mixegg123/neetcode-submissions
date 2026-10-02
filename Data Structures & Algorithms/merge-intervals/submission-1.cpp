class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort and expand right if overlap (prev.end >= cur.start, since sort-ed, compare one condition is sufficient)
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++)
        {
            //prev.end >= cur.start, overlap
            if(result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
