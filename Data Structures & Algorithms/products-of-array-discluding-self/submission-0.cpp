class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
#if 1
/*
提示 1: ans[i] = 「i 左邊所有數的乘積」×「i 右邊所有數的乘積」。

提示 2: 「左邊所有數的乘積」可以從左往右掃一次,一路累乘出來(prefix product)。「右邊」同理,從右往左掃。

nums:       [1,  2,  3,  4]
左邊乘積:   [1,  1,  2,  6]     (index 0 左邊沒有東西 → 1)
右邊乘積:   [24, 12, 4,  1]     (index n-1 右邊沒有東西 → 1)
相乘:       [24, 12, 8,  6]  ✓
*/
    //left product and right product
        int n = nums.size();
        vector<int> lproduct(n, 1);
        vector<int> rproduct(n, 1);
        vector<int> ans(n, 0);
        for(int i = 0;i<n;i++)
            if(i>0) lproduct[i] = lproduct[i-1] * nums[i-1];
        for(int i = n-1;i>=0;i--)
            if(i<n-1) rproduct[i] = rproduct[i+1] * nums[i+1];
        for(int i = 0;i<n;i++)
            ans[i] = lproduct[i] * rproduct[i];
        return ans;
#else
        int n = nums.size();
        vector<int> ans(n, 0);
        int zero = 0;
        int product = 1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0){
                zero++;
                continue;
            }
            product = product * nums[i];
        }

        if(zero > 1)
            return ans;

        for(int i = 0;i<nums.size();i++)
        {
            if(zero == 1)
            {   
                if(nums[i] == 0)
                    ans[i] = product;
            } else
                ans[i] = product/nums[i];
        }
        return ans;
#endif
    }
};
