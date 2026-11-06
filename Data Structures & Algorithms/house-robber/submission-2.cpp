class Solution {
public:
    int rob(vector<int>& nums) {
        //take or skip
        int take = 0;
        int skip = 0;

        for(int num : nums)
        {
            int old_take = take;
            int old_skip = skip;

            take = old_skip + num;
            skip = max(old_skip, old_take);
        }
        return max(take, skip);
    }
};
