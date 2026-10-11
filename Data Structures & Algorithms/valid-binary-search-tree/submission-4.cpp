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
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode *node, int MinVal, int MaxVal)
    {
/*

        5
       / \
      1   4
         / \
        3   6
*/
        if(!node) return true;
        //printf("node->val:%d Min:%d,Max:%d\n", node->val, MinVal, MaxVal);
        return dfs(node->left,MinVal,node->val) &&
         dfs(node->right, node->val, MaxVal) && (MinVal < node->val) && (node->val < MaxVal);

    }
};
