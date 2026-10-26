class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
//
//總和  −m  ...  −1   0   1  ...  +m
//index  0  ...  m−1  m  m+1 ... 2m
        int n = nums.size();
        int m = 0;

        for(auto num : nums)
            m += num;
        if(abs(target) > m)
            return 0;   
        //-m~m -> 2*m+1
        vector<vector<int>> dp(n+1, vector<int>(2*m+1, 0));
        //0個數組 對於總和0, method is 1
        //since we shit -m~m to 0 ~2m
        //dp[0][-m~m] -> dp[0][0~2m]
        dp[0][m] = 1;
/*
Failing case:nums = [3, 1, 1],target = 1
-5 ~ 5
唯一正解: +3 −1 −1 = 1
[1, 1 ] target = 2
dp[0][2] = 1;
for(int i = 1;i<=2;i++)
    for(j = -2 ~ 2)
    dp[1][0] = dp[0][-1] X
    dp[1][0] = dp[0][1] ->0

    dp[1][1] = dp[0][0]
    dp[1][1] = dp[0][1] ->0
    j = 0
    dp[1][2] = dp[0][1]->0
    dp[1][2] = dp[0][3]->0
    j=1
    dp[1][3] = dp[0][2];->0
    dp[1][3] = dp[0][4]; ->1
    j=2
    do[1][4] = dp[0][3]
    dp[1][4] = dp[0][5]
    --
    dp[2][4] = dp[1][3] -> 1
    dp[2][4] = dp[1][5]
-2 ~ 2 -> 0~4
過程:
  用了第 1 個: +3      → 總和 3   ← 超出 −1 ~ +1 了!
  用了第 2 個: +3 −1   → 總和 2   ← 還是超出
  用了第 3 個: +3 −1 −1 → 總和 1  ✓
*/
        //printf("n:%d m:%d\n", n, m);
        for(int i = 1;i<=n;i++)
        {
            for(int j = -m;j<=m;j++)
            {
                if(j+m-nums[i-1] >=0)
                    dp[i][j+m] += dp[i-1][j+m-nums[i-1]];
                if(j+m+nums[i-1] <=(2*m))
                     dp[i][j+m] += dp[i-1][j+m+nums[i-1]];
            }
        }
        return dp[n][target+m];
    }
};
