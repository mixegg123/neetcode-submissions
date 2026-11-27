class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1, duplicate = nums[0];

        for(int r = 1;r<nums.size();r++)
        {
            if(r>0 && nums[r-1] != nums[r])
            {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};