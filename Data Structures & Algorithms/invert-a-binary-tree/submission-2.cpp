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
    TreeNode* invertTree(TreeNode* root) {
        //dfs
        //base condtion, if(!root)
        //swap
        //dfs(root->left)
        //dfs(root->right)
        //dfs(root);
        if(!root) return NULL;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void dfs(TreeNode *root)
    {
        if(!root)
            return;
        swap(root->left, root->right);
        dfs(root->left);
        dfs(root->right);
    }
};
