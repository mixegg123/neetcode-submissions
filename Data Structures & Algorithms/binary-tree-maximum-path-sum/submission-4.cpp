/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
    
    int dfs(TreeNode *root)
    {
        if(!root) return 0;

        int lsum = max(0, dfs(root->left));
        int rsum = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + lsum + rsum);

        return root->val + max(lsum, rsum);
    }
};
