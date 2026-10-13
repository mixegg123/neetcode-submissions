class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //a sort vector<int> in unordered_set to avoid duplicate
        vector<vector<int>> result;
        vector<int> ans;
        set<vector<int>> se;
        //dfs(nums, 0, result, ans, se);

        //同層去重，不同層可重複選。
        sort(nums.begin(), nums.end());
        dfs2(nums, 0, result, ans);
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
    void dfs2(vector<int> &nums, int start, vector<vector<int>> &res, vector<int> &tmp)
    {
        res.push_back(tmp);

        for(int i = start; i<nums.size(); i++)
        {
            if(i>start && nums[i] == nums[i-1])
                continue;
            tmp.push_back(nums[i]);
            dfs2(nums, i+1, res, tmp);
            tmp.pop_back();
        }

    }
};
