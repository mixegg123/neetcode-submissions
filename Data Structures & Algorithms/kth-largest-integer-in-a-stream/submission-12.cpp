class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int target = 0;
public:

    KthLargest(int k, vector<int>& nums) {
        target = k;
        for(int num:nums)
            add(num);
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > target)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
