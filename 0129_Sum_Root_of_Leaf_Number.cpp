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
    int sumNumbers(TreeNode* root) {
        int res = helper(root, 0);
        return res;
    }
    int helper(TreeNode* root, int cummulate)
    {
        if(!root) return 0;
        int val = cummulate * 10 + root->val;
        if(!root->right && !root->left)
        {
            return val;
        }
        return helper(root->left, val) + helper(root->right, val);
    }
};

