class Solution {
public:
    string reorganizeString(string s) {
        //priority_queue<int, char> pq <count, char>
        //nums to record count
        string ans;
        priority_queue<pair<int, char>> pq;
        int nums[26] = {0};

        for(const char &c: s)
            nums[c-'a']++;
        for(int i = 0;i<26;i++)
            if(nums[i])
                pq.push({nums[i], i+'a'});

        char prev = '\0';
        while(!pq.empty())
        {
            char cur = pq.top().second; pq.pop();
            ans += cur;
            nums[cur-'a']--;

            if(prev != '\0' && nums[prev-'a'])
                pq.push({nums[prev-'a'], prev});

            prev = cur;
        }

        return ans.size() == s.size() ? ans : "";
    }
};