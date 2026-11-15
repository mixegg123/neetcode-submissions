class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
#if 1// miniHeap
        //using pair to sort <value, idx> is a good idea
        using P = pair<int, int>;
        int n = intervals.size();
        //priority queue <len, end>
        priority_queue<P, vector<P>, greater<P>> miniHeap;
        vector<P> pq;
        vector<int> ans(queries.size(), -1);
        for(int i = 0;i<queries.size(); i++)
            pq.push_back({queries[i], i});

        sort(pq.begin(), pq.end());
        sort(intervals.begin(), intervals.end());

        int i = 0;
        for(auto [val, idx] : pq)
        {
            //insert priority_queue when val >= intervals.start

            while(i<n && intervals[i][0] <= val)
            {
                int l = intervals[i][1] - intervals[i][0] + 1;
                    miniHeap.push({l, intervals[i][1]});
                i++;
            }

            //drop the interval already behind the query
            while(!miniHeap.empty() && miniHeap.top().second < val)
            {
                miniHeap.pop();
            }

            if(!miniHeap.empty())
                ans[idx] = miniHeap.top().first;
            //otherwise keep -1, no interval can fulfill
        }
        return ans;
#else
        sort(intervals.begin(), intervals.end());
        int n = queries.size();
        vector<int> ans;

        for(int query: queries)
        {
            int result = INT_MAX;
            for(int i = 0;i<intervals.size();i++)
            {
                int l = intervals[i][0];
                int r = intervals[i][1];
                if(l<=query && query<=r)
                    result = min(result, r-l+1);
            }
            if(result != INT_MAX)
                ans.push_back(result);
            else
                ans.push_back(-1);
        }
        return ans;
#endif
    }
};
