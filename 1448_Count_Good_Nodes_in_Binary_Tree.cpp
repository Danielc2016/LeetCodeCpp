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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root->val, root->val, root, res);
        return res;
    }
    void dfs(int rootVal, int pathMax,
             TreeNode* root, int& res)
    {
        if(root->val >= rootVal &&
           root->val >= pathMax)
        {
            res++;
        }
        pathMax = max(pathMax, root->val);
        if(root->left)
            dfs(root->val, pathMax, root->left, res);
        if(root->right)
            dfs(root->val, pathMax, root->right, res);
    }
};
//dfs
