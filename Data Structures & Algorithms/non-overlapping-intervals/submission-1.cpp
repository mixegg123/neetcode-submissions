class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort intervals
        //and keep a preEnd, if it overlap sec, extend the prevEnd by min and cnt+1 (means remove one interval)
        //if they are not overlap, updat preEnd to the sec internal
        //return the cnt

        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int cnt = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(prevEnd > intervals[i][0])
            {
                prevEnd = min(prevEnd, intervals[i][1]);
                cnt++;
            }
            else
                prevEnd = intervals[i][1];
        }
        return cnt;
    }
};
