class Solution {
public:
    struct Node {
        Node *next[26] = {};
        string word = "";
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *head = new Node();
        vector<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        // build a tries, and a visited arrary. navigate the board and update if match (by checking whehter have node for next node, reach to a real word, copy it and clear to avoid duplicating)

        for(string word : words)
        {
            Node *cur = head;
            for(int i = 0;i<word.size();i++)
            {
                if(cur->next[word[i] - 'a'] == NULL)
                    cur->next[word[i] - 'a'] = new Node();
                cur = cur->next[word[i] - 'a'];
                
                if(i == word.size() - 1)
                    cur->word = word;
            }
        }
        
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size(); j++)
            {
                visited[i][j] = true;
                dfs(board, visited, i, j, head->next[board[i][j] - 'a'], ans);
                visited[i][j] = false;
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& b, vector<vector<bool>> &v, int x, int y, Node *root, vector<string> &ans)
    {
        if(!root)
            return;

        if(root->word != "")
        {
            ans.push_back(root->word);
            root->word = "";
            //return;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=b.size() || ny>= b[0].size() || v[nx][ny])
                continue;

            v[nx][ny] = true;
            dfs(b, v, nx, ny, root->next[b[nx][ny] - 'a'], ans);
            v[nx][ny] = false;
        }
    }
};
