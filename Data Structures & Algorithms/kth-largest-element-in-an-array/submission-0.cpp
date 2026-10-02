class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //kth larget element, minHeap (not default for priority_queue)
        priority_queue<int, vector<int>, greater<int>> q;

        for(const int num : nums)
        {
            q.push(num);

            if(q.size()> k )
                q.pop();
        }
        return q.top();
        
    }
};
