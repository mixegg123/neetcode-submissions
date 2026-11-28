class Solution {
public:
    vector<int> p;
    vector<int> r;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> id;//email->id;
        unordered_map<string, string> nm;//email->name
        vector<vector<string>> ans;
        for(auto &v : accounts)
        {
            for(int i = 1;i<v.size();i++)
            {
                if(id.find(v[i]) == id.end())
                    id[v[i]] = id.size();
                
                nm[v[i]] = v[0];
            }
        }

        p.resize(id.size());
        r.resize(id.size());
        iota(p.begin(), p.end(), 0);

        //unite them
        for(auto &acc : accounts)
        {
            for(int i = 2;i<acc.size();i++)
                unite(id[acc[1]], id[acc[i]]);
        }

        // 1. 依 root 分組
        unordered_map<int, vector<string>> g;
        for( auto &[email, n] : id)
        {
            //root -> email name
            g[find(n)].push_back(email);
        }
        // 2+3. 每組排序,名字放最前面
        for(auto &[root, emails] : g)
        {
            sort(emails.begin(), emails.end());
            vector<string> tmp(emails);
            tmp.insert(tmp.begin(), nm[emails[0]]);
            ans.push_back(tmp);
        }

        return ans;
    }

    int find(int x)
    {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb)
            return false;
        if(r[pb] > r[pa])
            swap(pa, pb);
        
        //balance by rank
        p[pb] = pa;
        if(r[pa] == r[pb])
            r[pa]++;

        return true;
    }
};