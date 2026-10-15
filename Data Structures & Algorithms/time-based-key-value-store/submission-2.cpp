class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //G G G R R R ---> seems looks for last Green:
        // if timestamp_prev <= timestamp
        //  ans = mid;
        //  l++;
        //<key <timestamp and value> >
        auto it = map.find(key);
        if(it == map.end())
            return "";
        auto &vec = it->second;
        int l = 0, r = vec.size()-1;
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            auto &[t, val] = vec[mid];
            if(t<=timestamp)
            {
                ans = mid;
                l++;
            }
            else
                r--;
        }
        return (ans == -1)?"":vec[ans].second;
    }
};
