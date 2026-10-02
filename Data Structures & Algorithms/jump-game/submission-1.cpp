class Solution {
public:
    bool canJump(vector<int>& nums) {
        //dp of course
        //no, from last index
#if 0 //reverse
        int n = nums.size();
        int target = n - 1;
        for(int i = n - 2; i>=0; i--)
        {
            if(nums[i] + i >= target)
                target = i;
        }

        return target == 0;
#else //forward
        int max_len = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(max_len >= i)
                max_len = max(max_len, nums[i] + i);
        }
        return max_len >= n-1;
#endif
    }
};
