class KthLargest {
public:
    vector<int> root;
    int target = 0;
    KthLargest(int k, vector<int>& nums) {
        for(int num:nums)
            root.push_back(num);
        target = k;
        sort(root.begin(), root.end());
    }
    
    int add(int val) {
        root.push_back(val);
        sort(root.begin(), root.end());

        return root[root.size()-target];
    }
};
