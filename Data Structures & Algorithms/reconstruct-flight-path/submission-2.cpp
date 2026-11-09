class Solution {
public:
    //map with <string, MinHeap>
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
/*
例子: 邊 A→B、B→C、C→A、A→D,從 A 出發

A 先走 A→B → B→C → C→A → 回到 A,A 還有 A→D
                         → 走 A→D → D 沒路了,記 D
                         → 回到 A,沒路了,記 A
                    → C 沒路了,記 C
               → B 沒路了,記 B
→ A 沒路了,記 A

答案是 A → B → C → A → D。
--
dfs(A):先走 A→B
  dfs(B):沒路 → 記 B           ← 終點最先記
回到 A,走 A→C
  dfs(C):走 C→A
    dfs(A):沒路 → 記 A
  C 沒路 → 記 C
A 沒路 → 記 A
*/
        vector<string> ans;
        for(auto s: tickets)
            //u->v
            m[s[0]].push(s[1]);
        dfs("JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(const string &s, vector<string> &ans)
    {
        //if we dont use reference, it's a copy...
        auto &q = m[s];
        while(!q.empty())
        {
            string st = q.top();q.pop();
            dfs(st, ans);
        }
        ans.push_back(s);
    }
};
