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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // dfs
        // base condition, null check
        // compare two node's value
        // dfs root->left and root->right node
        //return bool
        if(!q && !p) return true;
        if(!q || !p) return false;

        return (q->val == p->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
