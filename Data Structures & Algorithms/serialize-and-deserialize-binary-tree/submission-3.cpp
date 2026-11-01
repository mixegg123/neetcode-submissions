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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //preorder DFS (root → left → right)
        string ans = "";
        dfs_to_string(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //preorder DFS (root → left → right)
        int start = 0; //it need shift
        return dfs_to_tree(data, start);
    }

    TreeNode* dfs_to_tree(const string &d, int &start)
    {
        if(start >= (int) d.size() || d[start] == '#')
        {
            start+=2;
            return nullptr;
        }
        int pos = d.find(',', start);

        TreeNode *cur = new TreeNode(stoi(d.substr(start, pos-start)));
        start = pos+1;
    
        cur->left = dfs_to_tree(d, start);
        cur->right = dfs_to_tree(d, start);
        return cur;
    }

    void dfs_to_string(TreeNode *node, string &out)
    {
        if(!node)
        {
            out += "#,";
            return;
        }
        out += to_string(node->val) + ',';
        dfs_to_string(node->left, out);
        dfs_to_string(node->right, out);
        return;
    }
};
