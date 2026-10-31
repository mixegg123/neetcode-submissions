class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num : nums)
            s.insert(num);

        int ans = 0;
        for(auto num : s)
        //for(int i = 0;i<nums.size();i++)
        {
            if(!s.count(num-1))
            {
                int len = 1, start = num;
                while(s.find(num+len) !=s.end())
                    len++;
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
