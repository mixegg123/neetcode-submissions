class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> ans(3, false);
        for(auto &e : triplets)
        {
            if(e[0]>target[0] || e[1] > target[1] || e[2] > target[2])
                continue;
            //[5, 3 6]
            //[5, 2, 1] [4, 3 2], [3, 3, 6]
            
            if(e[0] == target[0])
                ans[0] = true;

            if(e[1] == target[1])
                ans[1] = true;

            if(e[2] == target[2])
                ans[2] = true;
        }

        for(int i =0;i<3;i++)
            if(ans[i] != true)
                return false;
        return true;
    }
};
