class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> result;
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);

        for(auto &e : edges)
        {
            if(!unite(e[0], e[1]))
            {
                result.push_back(e[0]);
                result.push_back(e[1]);
                break;
            }
        }
        return result;
    }

    int find(int edge)
    {
        if(parent[edge] != edge)
            parent[edge] = find(parent[edge]);
        return parent[edge];
    }

    bool unite(int A, int B)
    {
        int rootA = find(A);
        int rootB = find(B);

        //already connected, cycle will form
        if(rootA == rootB)
            return false;
        
        //parent of rootB change to rootA
        parent[rootB] = rootA;
        return true;
    }
};
