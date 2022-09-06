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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    
    TreeNode* dfs(TreeNode* root)
    {
        if(root->left)
        {
            root->left = dfs(root->left);
        }
        if(root->right)
        {
            root->right = dfs(root->right);
        }
        if( root->left == NULL && 
            root->right == NULL && root->val != 1 )
        {
            root = NULL;
        }
        return root;
    }
};


/*
        1
    0        1
0      0   0    1 

base case
left == null, right == null, val != 1
   root = NULL, return NULL

*/
