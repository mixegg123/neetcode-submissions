class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, ans = 0;
        //[l..r] [r+1...l]
        while(r<nums.size()-1)
        {
            int farnest = 0;
            for(int k = l;k<=r;k++)
            {
                farnest = max(farnest, k+nums[k]);

            }
            l = r+1;
            r = farnest;
            ans++;
        }
        return ans;
    }
};
