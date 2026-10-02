class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //backtracing
        //for(int i = 0;i<nums.size();i++)
        //dfs(start+1)
        vector<int> tmp;
        vector<vector<int>> result;
        dfs(nums, 0, tmp, result);
        return result;
    }

    void dfs(vector<int> &nums, int start, vector<int> &tmp, vector<vector<int>> &res)
    {
        int n = nums.size();

        res.push_back(tmp);

        if(start>=n)
            return;
    
        for(int i = start; i < n; i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, i+1, tmp, res);
            tmp.pop_back();
        }

        return;
    }
};
