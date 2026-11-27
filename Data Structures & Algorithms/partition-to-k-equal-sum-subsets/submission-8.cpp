class Solution {
public:
    int target = 0;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //sum/k, if %3 !=0, ret false
        //backtrace
        int sum = 0;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>());
        for(auto num : nums)
            sum += num;

        target = sum/k;
        if(sum%k)
            return false;
        if(nums[0] > target)
            return false;

        return dfs(nums, 0, visited, target, k);
    }

    bool dfs(vector<int> &n, int start, vector<bool> &v, int cur, int k)
    {
        if(k == 1)
            return true;

        //recount
        if(cur == 0)
        {
            return dfs(n, 0, v, target, k - 1);
        }
        for(int i = start; i<n.size();i++)
        {
            if(v[i] || (cur-n[i] < 0)) 
                continue;
            v[i] = true;
            if(dfs(n, i+1, v, cur-n[i], k))
                return true;
            v[i] = false;
        }
        return false;
    }
};