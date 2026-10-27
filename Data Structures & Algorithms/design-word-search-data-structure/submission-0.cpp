class WordDictionary {
public:
    struct Node {
        Node *next[26] = {};
        bool isEnd = false;
    };

    Node *dummy;
    WordDictionary() {
        dummy = new Node();
    }
    
    void addWord(string word) {
        Node *cur = dummy;

        for(auto &c : word)
        {
            if(!cur->next[c-'a'])
                cur->next[c-'a'] = new Node();
            cur = cur->next[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node *cur = dummy;

        for(int i = 0;i<word.size();i++)
        {
            if(word[i] == '.')
            {
                bool ret = false;
                for(int j = 0;j<26;j++)
                {
                    if(cur->next[j])
                        ret |= dfs(word, i+1, cur->next[j]);
                }
                return ret;
            }
            else if(cur->next[word[i] - 'a'])
            {
                cur = cur->next[word[i] - 'a'];
            }
            else 
                return false; 
        }

        return cur->isEnd;
    }

    bool dfs(string &s, int start, Node *cur)
    {
        if(s.size() == start)
        { 
            if( cur->isEnd)
                return true;
            else
                return false;
        }

        if(s[start] == '.')
        {
            bool ret;
            for(int i = 0;i<26;i++)
                if(cur->next[i])
                    ret |= dfs(s, start+1, cur->next[i]);
            return ret;
        } else if (cur->next[s[start]-'a'])
        {
            return dfs(s, start+1, cur->next[s[start]-'a']);
        }
        else
            return false;
    }
};
