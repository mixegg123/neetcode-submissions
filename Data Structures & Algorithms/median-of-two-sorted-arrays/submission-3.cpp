class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //O(m+n)
        int m = nums1.size();
        int n = nums2.size();
        if(m+n==1)
        {
            return nums1.empty()?nums2[0]:nums1[0];
        }
        vector<double> ans;
        int half = (m+n) / 2;
        int i = 0, j = 0;
        while(i<m && j<n && ans.size()<=half)
        {
            if(nums1[i] <= nums2[j])
            {
                ans.push_back(nums1[i++]);
            } else 
            {
                ans.push_back(nums2[j++]);                
            }
        }

        while(ans.size()<=half && i<m)
            ans.push_back(nums1[i++]);

        while(ans.size()<=half && j<n)
            ans.push_back(nums2[j++]);
 
        //odd or even
        return((m+n)%2) ? ans.back() : (ans.back() + ans[ans.size()-2])/2.0;
    }
};
