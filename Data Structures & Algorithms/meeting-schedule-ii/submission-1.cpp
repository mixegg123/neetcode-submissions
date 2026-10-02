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
        //I saw before, this case use pair, 1 for start, end for -1, so we can use that to find the max room is need at a time
        using P = pair<int, int>;
        vector<P> rooms;
        for(auto interval : intervals)
        {
            //star time: need a room; end time, finish a room
            rooms.push_back({interval.start, 1});
            rooms.push_back({interval.end, -1});
        }
        sort(rooms.begin(), rooms.end());

        int cnt = 0, ans = 0;
        for(auto &room : rooms)
        {
            cnt += (room.second);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
