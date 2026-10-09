class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(const string s: strs)
        {
            vector<int> count(26, 0);
            for(const char c : s)
                count[c-'a']++;
            string key = "";
            for(int i = 0;i<26;i++)
            {
                key += to_string(count[i]) + '#';
            }
           // printf("key: %s\n",key.c_str());
            m[key].push_back(s);
        }
        for(auto &tmp : m)
        {
            res.push_back(tmp.second);
        }
        return res;
    }
};
