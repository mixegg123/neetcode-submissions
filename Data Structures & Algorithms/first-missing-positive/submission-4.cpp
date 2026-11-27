class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //答案一定在 1 ~ n+1 之間。比 n 大的數、0、負數,都不可能影響答案。
/*
第 1 個迴圈:把每個數字放回它該在的位置
for i = 0 到 n−1:
    while  nums[i] 在 1~n 之間
      且  nums[i] 該去的位置(index nums[i]−1)上,還不是這個數字:
        swap(nums[i], nums[nums[i] − 1])

第 2 個迴圈:找第一個對不上的
for i = 0 到 n−1:
    if nums[i] != i + 1 → 答案是 i + 1
全部都對 → 答案是 n + 1
*/
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0;i<nums.size();i++)
        {
#if 1
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
#else
            if(nums[i]>=1 && nums[i]<=n)
                ans[nums[i]-1]++;
#endif
        }

        for(int i = 0;i<n;i++)
        {
#if 0
            if(ans[i] == 0)
                return i+1;
#else
            if(nums[i] != i+1)
                return i+1;
#endif
        }
        return n+1;
    }
};