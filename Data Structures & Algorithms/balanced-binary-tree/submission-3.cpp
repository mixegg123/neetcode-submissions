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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            int LH = height(node->left);
            int RH = height(node->right);
            if(abs(LH-RH) >= 2)
                return false;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return true;
        //compare left/right tree height and if their abs difference less than 2, return true, otherwise it's not height balance tree..

    }

    int height(TreeNode *node)
    {
        if(!node) return 0;
        int L = height(node->left);
        int R = height(node->right);
        return max(L, R) + 1;
    }
};
