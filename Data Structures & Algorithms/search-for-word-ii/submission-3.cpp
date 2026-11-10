class Solution {
public:
    vector<string> ans;
    struct ListNode {
        ListNode *next[26] = {nullptr};
        string word = "";
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //tries, and isEnd replace by the word!

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        ListNode dummy;
        ListNode *cur = &dummy;

        for(string &word: words)
        {
            cur = &dummy;
            for(char &c: word)
            {
                if(!cur->next[c-'a'])
                    cur->next[c-'a'] = new ListNode();
                cur = cur->next[c-'a'];
            }
            cur->word = word;
        }

        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                visited[i][j] = true;
                dfs(board, dummy.next[board[i][j] - 'a'], i, j, visited);
                visited[i][j] = false;
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &b, ListNode *cur, int x, int y, vector<vector<bool>> &v)
    {
        if(!cur)
            return;
    
        if(cur->word != "")
        {
            ans.push_back(cur->word);
            cur->word = "";
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=b.size()||ny<0||ny>=b[0].size()||v[nx][ny])
            continue;

            v[nx][ny] = true;
            dfs(b, cur->next[b[nx][ny] - 'a'], nx, ny, v);
            v[nx][ny] = false;
        }
    }
};
