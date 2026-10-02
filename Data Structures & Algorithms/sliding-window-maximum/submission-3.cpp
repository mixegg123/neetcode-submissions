class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //a pair priority_queue, MaxHeap, to store, pair is {X,Y}, X is value, Y is index
        //so if index is not in the left or right range, discard to find next max
        using P = pair<int, int>;
        priority_queue<P> pq;
        vector<int> result;
        int n = nums.size();
        int l = 0;

        for(int r = 0; r<n; r++)
        {
            pq.push({nums[r], r});
#if 0//using l
            //only pop while size over 3, and top's index is left behind l
            while(pq.size() > k && (l > pq.top().second))
                pq.pop();

            if(r-l+1 == k)
            {
                result.push_back(pq.top().first);
                l++;
            }
#else
            //not using l

            if(r>=k-1)
            {
                while(pq.top().second <= r-k)
                    pq.pop();
                result.push_back(pq.top().first);
            }
#endif
        }
        return result;
    }
};
