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

因為 root 沒有 ancestor，所以一開始沒有任何上下界限制。
概念上就是：

-infinite < root.val < +infinite

*/
        if(!node) return true;
        //printf("node->val:%d Min:%d,Max:%d\n", node->val, MinVal, MaxVal);
        return dfs(node->left,MinVal,node->val) &&
         dfs(node->right, node->val, MaxVal) && (MinVal < node->val) && (node->val < MaxVal);

    }
};
