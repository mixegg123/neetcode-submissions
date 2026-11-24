class CountSquares {
public:
    int cnt[1001][1001] = {};
    vector<pair<int,int>> record; //<x, y>
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
        if(cnt[point[0]][point[1]] == 1)
            record.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int ans = 0;
        //point is qx and qy
        int qx = point[0];
        int qy = point[1];
        for(auto &[x, y] : record)
        {
            if(abs(qx - x) == abs(qy - y) && qx != x && qy != y )
            {
                //two more points
                //{qx, y} and {x, qy} and original {x, y}
                ans += (cnt[qx][y]*cnt[x][qy]*cnt[x][y]);
            }
        }
        return ans;
    }
};
