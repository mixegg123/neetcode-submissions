class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node *next;
        Node *prev;
    };
    int cap;
    int size;
    Node dummy;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) : cap(capacity), size(0) {
        dummy.next = NULL;
        dummy.prev = NULL;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;

        Node *cur = m[key];
        int val = cur->value;
        remove(cur);
        addToTail(cur);
        return val;
    }
    
    void put(int key, int value) {
        //1. find the node
        // a. not exist, create new
        // b. exist, get node
        //2. if exceed capacity, delete LRU node (in head)
        //3. add to the tail
        Node *tmp;
        if(m.find(key) == m.end())
        {
            tmp = new Node();
            tmp->key = key;
            tmp->value = value;
            tmp->next = NULL;
            tmp->prev = NULL;
        }
        else
        {
            tmp = m[key];
            tmp->value = value;
            //remove the node anyway
            remove(tmp);
        }

        //if still exceed cap, remove LRU one
        if(size >= cap)
            removeLRU();

        //add to tail
        addToTail(tmp);
    }

private:
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
};
