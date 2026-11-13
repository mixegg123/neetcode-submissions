class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
//We can find the index of each square by the equation (row / 3) * 3 + (col / 3).   
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> sqa(9);

        for(int i = 0; i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                char cur = board[i][j];
                int idx = (i/3)*3 +j/3;

                if(cur == '.')
                    continue;

                if(row[i].find(cur)!=row[i].end() || col[j].find(cur)!=col[j].end() || sqa[idx].find(cur) != sqa[idx].end())
                return false;
                
                row[i].insert(cur);
                col[j].insert(cur);
                sqa[idx].insert(cur);
            }
        }
        return true;

    }
};
