class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp; 
        dfs(nums, 0, tmp, target);
        return res;
    }

    void dfs(vector<int> &nums, int start, vector<int> &tmp, int target)
    {
        if(target < 0)
            return;

        if(target == 0)
        {
            res.push_back(tmp);
            return;
        }

        for(int i = start ; i<nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, i, tmp, target - nums[i]);
            tmp.pop_back();
        }
        return;
    }
};
