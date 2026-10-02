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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int longestLength = 0;
        while(!q.empty())
        {
            int lh = 0, rh = 0;
            TreeNode *node = q.front();q.pop();

            if(node->left)
            {
                lh = height(node->left);
                q.push(node->left);
            }
            if(node->right)
            {
                rh = height(node->right);
                q.push(node->right);
            }
            longestLength = max(longestLength, lh+rh);
        }

        return longestLength;
    }

    int height(TreeNode *node)
    {
        if(!node) return 0;

        int L = height(node->left);
        int R = height(node->right);

        return max(L, R) + 1;
    }
};
