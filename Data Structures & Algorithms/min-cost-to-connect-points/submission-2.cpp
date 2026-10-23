class Solution {
public:
    vector<int> parent;

    int minCostConnectPoints(vector<vector<int>>& points) {
        //Kruskai + Uion Find
        vector<tuple<int, int, int>> vec; //{w, u, v};
        int n = points.size();
        parent.resize(n);
        for(int i =0;i<n;i++)
            parent[i] = i;
        int ans = 0, num_edges = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vec.push_back({w, i, j});
            }
        }
        //sort by weigh (manhattan dist)
        sort(vec.begin(), vec.end());

        for(auto [w, u, v] : vec)
        {
            if(unite(u, v))
            {
                ans += w;
                num_edges++;
            }

            if(num_edges == (n-1))
                break;
        }
        return ans;
    }
    //true is can connect, false means already connect
    bool unite(int a, int b)
    {
        int p_a = find(a);
        int p_b = find(b);

        if(p_a == p_b)
            return false;
        //b's parent to a
        parent[p_b] = p_a;

        return true;
    }

    int find(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
};
