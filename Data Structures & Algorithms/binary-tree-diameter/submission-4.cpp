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
        
        int ans = 0;
        height(root, ans);
        return ans;
    }

    int height(TreeNode *node, int &ans)
    {
        if(!node) return 0;
        int L = 0, R = 0;

        L = height(node->left, ans);
        R = height(node->right, ans);

        ans = max(ans, L+R);

        return 1 + max(L, R);
    }
};
