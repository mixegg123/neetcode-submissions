class Solution {
public:
    int search(vector<int>& nums, int target) {
        //1. binary search
        //2. find the pivot index irst

        int l = 0, r = nums.size()-1;
        int ans = -1;
        int pivot = find_pivot(nums);
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            //left side sort
            if(nums[l] <= nums[mid])
            {
                    //here
                    if(nums[l] <= target && target < nums[mid])
                        r = mid - 1;
                    else
                        l = mid + 1;
            } 
            // right side sort
            else
            {
                //here
                if(nums[r] >= target && target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        
        return -1;

    }

    int find_pivot(vector<int> &nums)
    {

        //find pviot;
        int l = 0,  r = nums.size()-1;
        int ans = 0;
        while(l<=r)
        {
            //compare r?
            int mid = l + (r-l)/2;
            if(nums[mid]<=nums.back())
            {
                ans = mid;
                r = mid - 1;
            } else
            {
                //nums[mid] > nums[r]
                l = mid + 1;
            }

        }
        //printf("pivot: %d", ans);
        return ans;
    }
};
