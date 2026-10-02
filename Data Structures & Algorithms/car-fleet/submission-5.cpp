class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //所以最靠近終點的那台車,抵達時間完全不受任何人影響
        //map<int, int> position, idx?
        //push if stack is empty, or stack.top() < new times
        unordered_map<int, int> m;
        stack<double> st;
        //position is unique
        for(int i = 0; i< position.size();i++)
            m[position[i]] = speed[i];
        
        sort(position.begin(), position.end(), greater<int>());
        for(int i = 0; i< position.size();i++)
        {
            double time = (double(target-position[i]))/(m[position[i]]);
            if(st.empty() || st.top() < time)
                st.push(time);
        }

        return st.size();
    }
};
