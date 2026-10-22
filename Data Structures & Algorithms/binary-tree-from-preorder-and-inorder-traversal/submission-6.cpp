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
    int preorderIdx = 0;
    unordered_map<int, int> m;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder -> root l r
        //inorder -> l root r
        //use inorder to bisect l and r
        
        for(int i = 0; i < inorder.size();i++)
            m[inorder[i]] = i;
        
        return dfs(preorder, inorder, 0, preorder.size()-1);
    }

    TreeNode *dfs(vector<int> &p, vector<int> &i, int l, int r)
    {
        if(l>r)
            return NULL;

        TreeNode *node = new TreeNode(p[preorderIdx]);
        int mid = m[p[preorderIdx]];// it is root
        
        preorderIdx++;
    
        node->left = dfs(p, i, l, mid-1);
        node->right = dfs(p, i, mid+1, r);

        return node;
    }

};
