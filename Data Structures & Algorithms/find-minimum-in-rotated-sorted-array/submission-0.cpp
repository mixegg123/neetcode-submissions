class Solution {
public:
    int findMin(vector<int> &nums) {
        //of course the binary search
        //left ascending and righ ascending
        //4 5 0 1 2 3 -->l=0,r=5, mid = 2
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            //using last element as an achnor
            int last = nums.back();
            // two peak, one is high, the other shall be lower
            //[3, 4, 5, 6, 1 2]
            //[F, F, F, F ,T, T]
            //l = 0, r =5, mid = 2;
            //l = 3, r = 5, mid = 4;
            //l = 3, r = 3, mid = 3 --> l= 4
            if(last <  nums[mid])
            {
                l = mid + 1;
            } else
            //nums[r] >= nums[mid] 
            {
                ans = mid;
                r = mid - 1;
            }
        }
        return nums[ans];
    }
};
