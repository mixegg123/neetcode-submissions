/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        using P = pair<int, int>; // <time, and +-1>
        int ans = 0;
        vector<P> v;
    
        for(auto &e : intervals)
        {
            v.push_back({e.start, 1});
            v.push_back({e.end, -1});
        }
        sort(v.begin(), v.end());

        int tmp = 0;
        for(auto [time, count] : v)
        {
            tmp += count;
            ans = max(ans, tmp);
        }
        return ans;
    }
};
