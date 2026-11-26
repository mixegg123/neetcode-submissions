class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //sum/k, if %3 !=0, ret false
        //backtrace
        int sum = 0, target = 0;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>());
        for(auto num : nums)
            sum += num;

        target = sum/k;
        if(sum%k)
            return false;
        if(nums[0] > target)
            return false;

        //5 4 3 2 1
        for(int i = 0; i<nums.size();i++)
        {
            if(visited[i]) continue;
            dfs(nums, i, visited, target, k);
        }
        return k == 0;
    }

    bool dfs(vector<int> &n, int start, vector<bool> &v, int target, int &k)
    {
        if(target < 0)
            return false;

        if(target == 0)
        {
            k--;
            return true;
        }

        for(int i = start; i<n.size();i++)
        {
            if(v[i]) continue;
            v[i] = true;
            if(dfs(n, i+1, v, target-n[i], k))
                return true;
            v[i] = false;
        }
        return false;
    }
};