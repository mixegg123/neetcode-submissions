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
private:
    void dfs(TreeNode *node, int &k, int &ans)
    {
        if(!node) return;
        dfs(node->left, k, ans);
        k--;
        if(k == 0)
        {
            ans = node->val;
            return;
        }
        dfs(node->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        //kth samllest --> maxHeap? and queue to navigator tree
#if 1 //inorder the k member
        int ans = 0;
        dfs(root, k, ans);
        return ans;
#else // BFS
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
#endif
    }
};
