class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
#if 1 //using deque
        //。這題一定要學「單調 deque」,O(n)
        deque<int> dq;
        int l = 0, r = 0;
        int n = nums.size();
        vector<int> res;
        while(r<n)
        {
            //decreasing order
            while(!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();
            dq.push_back(r);

            if(l > dq.front())
                dq.pop_front();

            if((r+1)>=k)
            {
                res.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return res;
#else
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
#endif
    }
};
