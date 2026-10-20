class Solution {
public:
    string reorganizeString(string s) {
        //maxHeap //<count, char>
        priority_queue<pair<int, char>> pq;
        string ans;
        int nums[26] = {0};

        for(const char &c : s)
            nums[c-'a']++;

        for(int i = 0;i<26;i++)
            if(nums[i])
                pq.push({nums[i], i+'a'});

        char prev = '\0';
        while(!pq.empty())
        {
            char c = pq.top().second;pq.pop();
            nums[c-'a']--;
            ans += c;

            if(prev != '\0' && nums[prev-'a'])
                pq.push({nums[prev-'a'], prev});
            prev = c;
        }
        return ans.size() == s.size()?ans:"";
    }
};