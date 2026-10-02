class PrefixTree {
private:
    struct Node {
        Node *next[26]={};
        bool isEnd;
    };
    struct Node *root;
public:

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        struct Node *tmp = root;
        for(const char c : word)
        {
            if(tmp->next[c-'a'] == NULL)
            {
                tmp->next[c-'a'] = new Node();
            }
            tmp = tmp->next[c-'a'];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        struct Node *tmp = root;
        for(const char c : word)
        {
            if(tmp->next[c-'a'])
                tmp = tmp->next[c-'a'];
            else
                return false;
        }
        if(tmp->isEnd)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        struct Node *tmp = root;
        for(const char c : prefix)
        {
            if(tmp->next[c-'a'])
                tmp = tmp->next[c-'a'];
            else
                return false;
        }
        return true;        
    }
};
