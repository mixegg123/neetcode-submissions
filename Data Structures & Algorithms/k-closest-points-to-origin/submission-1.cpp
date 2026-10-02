class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        //int m = points[0].size()--> 2
        //answer and position
        //k minimal,  maxHeap? a pair? <answer, index>
        priority_queue<pair<int, int>, vector<pair<int,int>>> q;
        for(int i = 0; i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            q.push({x*x+y*y, i});
            printf("v[0]:%d,v[1]:%d\n",x,y);

            if(q.size() > k)
                q.pop();
        }

        //final answer
        while(!q.empty())
        {
            auto [val, i] = q.top();
            ans.push_back(points[i]);
            q.pop();
        }
        return ans;
    }
};
