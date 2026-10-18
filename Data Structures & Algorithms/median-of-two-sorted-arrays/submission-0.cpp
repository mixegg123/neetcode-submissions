class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //seems achieve by two priority_queue? MaxHeap / MinHeap
        //MaxHeap: half small, MinHeap: half bigger
        // 1 2 3 4 5 6 7
        //odd: max heap drop n/2
        //even: max/min heap drop half
        priority_queue<float> MaxHeap;
        priority_queue<float, vector<float>, greater<float>> MinHeap;
        for(const int num: nums1)
        {
            MaxHeap.push(num);
            MinHeap.push(num);
        }
        for(const int num: nums2)
        {
            MaxHeap.push(num);
            MinHeap.push(num);
        }
        int n = nums1.size()+nums2.size();

        float ans = 0;
        if(n%2)
        {
            n = n/2;
            while(n)
            {
                MaxHeap.pop();
                n--;
            }
            ans = MaxHeap.top();
        } else
        {
            n = n/2;
            while(n)
            {
                MaxHeap.pop();//2
                MinHeap.pop();//3
                n--;
            }
            //printf("max:%d, min:%d\n", MaxHeap.top(), MinHeap.top());
            ans = (MaxHeap.top() + MinHeap.top()) / 2.0;
        }
        return ans;
    }
};
