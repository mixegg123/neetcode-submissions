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
    int goodNodes(TreeNode* root) {
        int ans = 1;

        dfs(root->left, root->val, ans);
        dfs(root->right, root->val, ans);
        return ans;
    }

    void dfs(TreeNode *cur, int maxValue, int &ans)
    {
        if(!cur)
            return;
        
        if(cur->val >= maxValue)
            ans++;
        
        dfs(cur->left, max(cur->val, maxValue), ans);
        dfs(cur->right, max(cur->val, maxValue), ans);
    }
};
