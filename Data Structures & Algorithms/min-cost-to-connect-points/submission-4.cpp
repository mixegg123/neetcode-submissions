class Solution {
public:
    vector<int> parent;

    int minCostConnectPoints(vector<vector<int>>& points) {
        //Kruskai + Uion Find + greedy...
        int ans = 0;
        int n = points.size();
        vector<tuple<int,int,int>> v; // <w, u, v>
        parent.resize(n, 0);
        for(int i = 0;i<n;i++)
            parent[i] = i;

        for(int i = 0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int w = abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);
                v.push_back({w, i, j});
            }
        }
        sort(v.begin(), v.end());

        for(auto &[w, u, v] : v)
        {
            if(unite(u, v))
                ans += w;
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
        
        parent[p_b] = p_a;
        return true;
    }

    int find(int x)
    {
        return x == parent[x] ? x : parent[x] = find(parent[x]) ;
    }
};
