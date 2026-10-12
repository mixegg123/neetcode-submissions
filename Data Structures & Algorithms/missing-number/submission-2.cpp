class Solution {
public:
    int missingNumber(vector<int>& nums) {
#if 0// bad way
    sort(nums.begin(), nums.end());
    for(int i = 0;i<nums.size();i++)
        if(i != nums[i])
        {return i;}
    return nums.size();

#else //best xor...
    int n = nums.size();
    int ans = 0;

    for(int i = 0;i<=n;i++)
    {
        ans = ans^i;
        //printf("ans:0x%x, i:%d\n", ans, i);
    }
    //printf("intermiedate: ans : 0x%x\n", ans);
    for(int i = 0;i<n;i++)
    {
        //printf("ans:0x%x ^ nums[%d]:0x%x\n", ans, i, nums[i]);
        ans = ans^nums[i];
    }
    //printf("final: ans : 0x%x\n", ans);
    return ans;
#endif
    }
};
