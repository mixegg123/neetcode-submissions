class Twitter {
public:
/*

int time = 0;
unordered_map<int, unordered_set<int>> followMap;          // userId → 追蹤的人
unordered_map<int, vector<pair<int,int>>> tweetMap;        // userId → {時間, tweetId}

*/
    int time = 0;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> teeMap;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        teeMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // heap 每筆:{時間, tweetId, 哪個人, index}
        priority_queue<tuple<int,int,int,int>> pq;

        unordered_set<int> p = followMap[userId];
        p.insert(userId);

        //insert first one from user(s) to pq
        for(auto user: p)
        {
            auto &t = teeMap[user];
            if(t.empty()) continue;
            int idx = t.size() -1;
            pq.push({t[idx].first, t[idx].second, user, idx});
        }

        vector<int> ans;
        while(!pq.empty() && ans.size() < 10)
        {
            auto [tm, tweeId, userId, idx] = pq.top();pq.pop();
            auto &t = teeMap[userId];
            ans.push_back(tweeId);
            if(idx > 0)
                pq.push({t[idx-1].first, t[idx-1].second, userId, idx-1});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].find(followeeId) != followMap[followerId].end())
            followMap[followerId].erase(followeeId);
    }
};
