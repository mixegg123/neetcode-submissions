class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort
        // [-1, 0, 1, 2,-1, -4]
        // [-4,-1,-1, 0, 1,  2]
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target = -1*nums[i];

            int l = i+1;
            int r = n-1;
            //printf(">i:%d, l:%d, r:%d\n", i, l, r);
            while(l<r)
            {
                // [-4,-1,-1, 0, 1,  2]
                //printf("\t i:%d, l:%d, r:%d\n", i, l, r);
                if(target == (nums[l] + nums[r]))
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }
                else if(nums[l] + nums[r] < target)
                {
                    l++;
                    //while(l<r && nums[l] == nums[l-1]) l++;
                } else
                {
                    r--;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};
