class Solution {
public:
    int jump(vector<int>& nums) {
        //[l..r] [l=r+1... farnest]
        int l = 0, r = 0;
        int step = 0;
        while(r<nums.size()-1)
        {
            int farnest = 0;
            for(int i = l; i<=r;i++)
            {
                farnest = max(farnest, i+nums[i]);
            }
            l = r+1;
            r = farnest;
            step++;
        }
        return step;
    }
};
