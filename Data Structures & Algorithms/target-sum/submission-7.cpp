class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
/*
Target Sum(494)關鍵 recap

1. 狀態: dp[i][sum] = 前 i 個數字,每個都一定要加 ±,總和是 sum 的方法數

2. 範圍是 −m ~ +m,不是 −target ~ +target

m = 全部數字的總和
過程中的總和可能超過 target,之後再減回來([3,1,1], target=1)
陣列開 (n+1) × (2m+1),存取用 dp[i][sum + m]

3. 初始值 = 起點: dp[0][m] = 1

0 個數字 → 只有總和 0,1 種方法
總和 0 的 index 是 0 + m,不是 0
只有第 0 列這一格,其他列不能預設成 1(不能跳過數字)

4. 轉移:只有 + 和 −,沒有「跳過」

兩條路的方法數相加
讀寫前要檢查 index 在 0 ~ 2m
*/
        int n = nums.size();
        int m = 0;
        for(int &num : nums)
            m += num;

        if(abs(target) > m)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(2*m +1, 0));
        dp[0][m] = 1;// this is shift from sum result 0 + m as m;

        for(int i = 1;i<=n; i++)
        {
            //shift by m as we cannot accpet negative index in an array
            for(int sum = -1*m ; sum<=m; sum++)
            {
                if(sum + m - nums[i-1] >= 0)
                    dp[i][sum+m] += dp[i-1][sum+m-nums[i-1]];
                if(sum + m + nums[i-1] <= (2*m))
                    dp[i][sum+m] += dp[i-1][sum+m+nums[i-1]]; 
            }
        }
        return dp[n][target+m];
    }
};
