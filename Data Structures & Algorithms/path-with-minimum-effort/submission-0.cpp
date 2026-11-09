class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //Ｘ：memo + dfs
        //if difference > memo, return
        //Dijkstra
        using P = tuple<int,int,int>;
        priority_queue<P, vector<P>, greater<P>> q;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector(n, INT_MAX));
        //start from zero
        dist[0][0] = 0;
        //dist, x, y
        q.push({0, 0, 0});

        while(!q.empty())
        {
            auto [d, x, y] = q.top(); q.pop();

            if(x == m - 1 && y == n-1)
                return dist[x][y];
            if(d > dist[x][y])
                continue;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0||nx>=m||ny<0||ny>=n)
                    continue;
                int w = abs(heights[x][y] - heights[nx][ny]);
                //key here, inherit max from parent
                //沿路一路繼承下來的 running maximum。
                w = max(d,w);
                if(dist[nx][ny] > w)
                {
                    dist[nx][ny] = w;
                    q.push({w, nx, ny});
                }
            }
        }

        return 0;
    }
};