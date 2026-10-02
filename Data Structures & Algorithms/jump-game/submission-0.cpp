class Solution {
public:
    bool canJump(vector<int>& nums) {
        //dp of course
        //no, from last index
        int n = nums.size();
        int target = n - 1;
        for(int i = n - 2; i>=0; i--)
        {
            if(nums[i] + i >= target)
                target = i;
        }

        return target == 0;
        
    }
};
