/**
 * Definition for a binary tree node.
 // Daniel Chang
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
    // int height = 0;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = HeightHelper(root->left);
        int right = HeightHelper(root->right);
        if( abs(left - right) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int HeightHelper(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(HeightHelper(root->left), HeightHelper(root->right));
    }
};
