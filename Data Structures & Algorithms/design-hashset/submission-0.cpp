class MyHashSet {
public:
    int v[1000001] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(v[key] == 0)
            v[key]++;
    }
    
    void remove(int key) {
        if(v[key])
            v[key] = 0;
    }
    
    bool contains(int key) {
        return v[key] > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */