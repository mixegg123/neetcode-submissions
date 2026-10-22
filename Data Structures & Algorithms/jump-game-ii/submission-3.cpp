class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = nums[0];
        if(nums.size() == 1)
            return 0;
        if(l+r>=(nums.size()-1))
            return 1;
        //[l..r] [r+1...l]
        for(int i=1;i<nums.size();i++)
        {
            int farnest = 0;
            for(int k = l;k<=r;k++)
            {
                farnest = max(farnest, k+nums[k]);
                if(farnest >= nums.size()-1)
                    return i+1;
            }
            l = r+1;
            r = farnest;
        }
        return 0;
    }
};
