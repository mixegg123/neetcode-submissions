class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sort and skip duplicate..
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        //1,2,2,4,5,6,9 target 8
        vector<int> tmp;
        dfs(candidates, 0, target, tmp, ans);
        return ans;
    }

    void dfs(vector<int> &d, int start, int target, vector<int> &tmp, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(tmp);
            return;
        }

        for(int i = start; i<d.size();i++)
        {
//去重要在每一層都做:同一層裡,同一個值只能當「這個位置的選擇」一次。
            if(i>start && d[i-1] == d[i]) continue;
    
             if(d[i] > target)
                break;
            tmp.push_back(d[i]);
            dfs(d,i+1, target - d[i], tmp, ans);
            tmp.pop_back();
        }
    }
};
