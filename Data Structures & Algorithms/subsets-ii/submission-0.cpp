class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //a sort vector<int> in unordered_set to avoid duplicate
        vector<vector<int>> result;
        vector<int> ans;
        set<vector<int>> se;
        dfs(nums, 0, result, ans, se);
        return result;
    }

    void dfs(vector<int> &nums, int start, vector<vector<int>> &res, vector<int> &tmp, set<vector<int>> &se)
    {
        vector<int> sorted_tmp(tmp);
        sort(sorted_tmp.begin(), sorted_tmp.end());
        if(se.find(sorted_tmp) != se.end())
            return;

        res.push_back(tmp);
        se.insert(sorted_tmp);

        for(int i = start; i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, i+1, res, tmp, se);
            tmp.pop_back();
        }
    }
};
