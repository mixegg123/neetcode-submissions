class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //backtracing
        //for i j, find 2 then recurisve, else return
        //no, shall bfs and queue each rotte fruit, and pop each and navigator its neibhor, only queue if it's fresh fruit
        // a pair, good idea
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        //push first rottting fruit
        for(int i = 0; i < m; i++)
            for(int j = 0; j<n; j++)
                if(grid[i][j] == 2)
                {
                    printf("first: i%d,j%d\n", i, j);
                    q.push({i,j});
                }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        //bfs...
        while(!q.empty())
        {
            int loop = q.size();

            for(int k = 0; k < loop; k++) {
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0;i<4;i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];

                    if(nx<0 || nx>=m ||ny<0 ||ny>=n)
                        continue;
                    if(grid[nx][ny] == 1)
                    {
                        printf("iter: i%d,j%d\n", nx, ny);
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }

            if(q.size()) cnt++;
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        return cnt;
    }
};
