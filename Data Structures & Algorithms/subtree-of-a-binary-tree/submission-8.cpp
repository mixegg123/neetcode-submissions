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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
#if 1//BFS
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if(isIdentical(node, subRoot))
                return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
#else
        if(!subRoot) return true;
        if(!root) return false;

        if(isIdentical(root, subRoot)) 
            return true;
        return IsSubtree(root->left, SubRoot) ||
                IsSubtree(root->right, SubRoot);
#endif
    }

    bool isIdentical(TreeNode *p, TreeNode*q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;

        return p->val == q->val && 
            isIdentical(p->left, q->left) &&
            isIdentical(p->right, q->right);
    }

};
