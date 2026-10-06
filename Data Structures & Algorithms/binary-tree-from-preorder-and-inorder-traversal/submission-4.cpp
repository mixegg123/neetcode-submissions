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
    unordered_map<int, int> m;
    int preIdx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder: root -> left -> right
        //inorder:   left -> root -> right
        // the leftmost is root
        // new root find left root->left =, root ->rigt = the other side
        //前序的第一個 = 根;在中序裡找到根,左邊整段 = 左子樹,右邊整段 = 右子樹。hash map 只是讓「在中序裡找根的位置」
        //preorder 決定「下一個 root 是誰」；inorder 決定「這個 root 的左右子樹範圍」。


        //TreeNode* dfs(pre, in, mid, l ,r) // a private hash map
        //dfs
        //1. base condition
        //2. do something
        //3. next dfs, for left and right TreeNode
        //hash_map <val, idx>
        preIdx = 0;
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return dfs(preorder, 0, inorder.size()-1);

    }
    TreeNode* dfs(vector<int> & pre, int l, int r)
    {
        //if(l< 0 || r > pre.size())
        if(l>r)
            return NULL;
        //create root by preOrder's preIdx
        TreeNode *node = new TreeNode(pre[preIdx]);
        int mid = m[pre[preIdx]];
        preIdx++;
    
        node->left = dfs(pre, l, mid - 1);
        node->right = dfs(pre, mid + 1, r);
        return node;
    }
};
