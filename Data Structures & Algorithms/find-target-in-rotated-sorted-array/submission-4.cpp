class Solution {
public:
    int search(vector<int>& nums, int target) {

        //sort
        int l = 0, r = nums.size()-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
                return mid;
            printf("l: %d, r: %d, mid: %d, nums[mid]%d\n",l, r, mid, nums[mid]);
            //sort in left
            if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target && nums[mid] > target)
                {
                    r = mid - 1;
                } else
                {
                    l = mid + 1;
                }
            } 
            //sort in right
            else
            {
                if(nums[r] >= target && nums[mid] < target)
                {
                    l = mid + 1;
                } else
                {  
                    r = mid - 1;
                }
            }         
        }
        return -1;
    }
};
