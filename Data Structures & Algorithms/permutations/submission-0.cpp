class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //visited?
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(nums, tmp, visited, ans);
        return ans;
    }

    void dfs(vector<int> nums, vector<int> &t, vector<bool> &v, vector<vector<int>> &ans)
    {
        if(t.size() == nums.size())
        {
            ans.push_back(t);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(v[i]) continue;

            v[i] = true;
            t.push_back(nums[i]);
            dfs(nums, t, v, ans);
            t.pop_back();
            v[i] = false;
        }
    }
};
