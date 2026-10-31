class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num : nums)
            s.insert(num);

        int l = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                int len = 1, start = nums[i];
                while(s.find(++start) !=s.end())
                    len++;
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
