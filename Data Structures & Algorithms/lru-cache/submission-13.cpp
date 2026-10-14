class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v) : 
            key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    Node *left;
    Node *right;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) : cap(capacity) {
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(m.find(key) != m.end())
        {
            Node *cur = m[key];
            remove(cur);
            insert(cur);
            return cur->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            remove(m[key]);
            delete m[key];
        }
        m[key] = new Node(key, value);
        insert(m[key]);

        if(m.size() > cap)
        {
            //remove LRU
            Node *lru = left->next;
            remove(lru);
            m.erase(lru->key);
            delete lru;
        }
    }

private:

    //remove and insert, and left/right node
    void remove (Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    //inset to right (MRU)
    void insert(Node *node)
    {
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
#if 0
    void removeLRU()
    {
        Node *root = &dummy;
        Node *tmp = root->next;
        root->next = tmp->next;
        if(tmp->next)
            tmp->next->prev = root;
        m.erase(tmp->key);
        delete tmp;
        size--;       
    }

    //detach only, not delete
    void remove(Node *node)
    {
        if(m.find(node->key) != m.end())
        {
            Node *cur = m[node->key];
            Node* prev = cur->prev;
            prev->next = cur->next;
            if(cur->next)
                cur->next->prev = prev;
            cur->next = NULL;
            cur->prev = NULL;
            size--;
        }
    }
    
    void addToTail(Node *node)
    {
        Node *temp = &dummy;
        Node *cur = temp;
        while(temp)
        {
            cur = temp;
            temp = temp->next;
        }
        cur->next = node;
        node->prev = cur;
        m[node->key] = node;
        size++;
    }
#endif
};
