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
    int kthSmallest(TreeNode* root, int k) {
        //kth samllest --> maxHeap? and queue to navigator tree
        priority_queue<int> maxHeap;
        queue<TreeNode *> tree;

        if(root)
            tree.push(root);
        while(!tree.empty())
        {
            TreeNode *node = tree.front();
            tree.pop();
            maxHeap.push(node->val);

            if(maxHeap.size() > k)
                maxHeap.pop();

            if(node->left)
                tree.push(node->left);
                
            if(node->right)
                tree.push(node->right);
        }
        return maxHeap.top();
    }
};
