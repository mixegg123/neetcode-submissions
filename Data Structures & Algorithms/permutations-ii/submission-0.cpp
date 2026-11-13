class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, tmp, visited, ans);
        return ans;
    }

    void dfs(vector<int> &nums, vector<int> &tmp, vector<bool> &v, vector<vector<int>> &ans)
    {
        if(tmp.size() == nums.size())
        {
            ans.push_back(tmp);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
/*
v[i-1]	意思	動作
true(已用)	前一個相同的值在這條路徑上,放在前面的位置	可以用 nums[i],這是直的方向,[1, 1] 合法
false(沒用)	前一個相同的值在這一層剛剛被試過、又被撤銷了
*/
            if(i>0 && nums[i-1] == nums[i] && v[i-1])
                continue;
            if(v[i])
                continue;
            v[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, tmp, v, ans);
            tmp.pop_back();
            v[i] = false;

        }
    }

};