class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS w/ size
/*
Word Ladder 心智卡

對,就是一層一層的 BFS。 每一層 = 多改一個字母,第一次碰到 endWord 的層數就是答案。

字 = 點,差一個字母 = 邊,每步成本一樣 → BFS

*/
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        int step = 1;
        q.push(beginWord);

        while(!q.empty())
        {
            int size = q.size();
            
            for(int k = 0;k<size;k++)
            {
                string cur = q.front(); q.pop();

                if(cur == endWord)
                    return step;
            
                for(int i = 0;i<cur.size();i++)
                {
                    char tmp = cur[i];
                    for(int k = 0;k<26;k++)
                    {
                        cur[i] = k+'a';
                        if(dict.find(cur) != dict.end())
                        {
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            step++;
        }
        return 0;
    }
};
