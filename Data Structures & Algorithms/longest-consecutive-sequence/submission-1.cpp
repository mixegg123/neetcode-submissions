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
            if(s.find(num-1) == s.end())
            {
                int len = 1, start = num;
                while(s.find(++start) !=s.end())
                    len++;
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
