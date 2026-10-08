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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur;
        queue<TreeNode*> qe;

        qe.push(root);

        while(!qe.empty())
        {
            cur = qe.front();qe.pop();
            //1. p, q in left
            //2. p, q in right
            //3. or hit, a ascent, p or q is ascent
            if(cur->val > p->val && cur->val > q->val)
                qe.push(cur->left);
            else if(cur->val < p->val && cur->val < q->val)
                qe.push(cur->right);
            else
                return cur;
        }
        return NULL;
    }
};
