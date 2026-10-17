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
        //X: BFS, and navigater in level and keep a max high
        //DFS, take upper boud
/*
     3 
  1    4
3     1   5
*/
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }

    void dfs(TreeNode* node, int upper, int &ans)
    {
        if(!node) return;

        if(node->val >= upper)
            ans++;
        
        dfs(node->left, max(upper, node->val) ,ans);
        dfs(node->right, max(upper, node->val), ans);
    }
};
