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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //bool res = false;
        return isEqual(root, subRoot)
            || ( root->left && isSubtree(root->left, subRoot) )
            || ( root->right && isSubtree(root->right, subRoot) );
    }
    bool isEqual(TreeNode* r, TreeNode* s)
    {
        if(!r || !s)
            return r==s; // clever tech!
        return (r->val == s->val) 
            && isEqual(r->right, s->right)
            && isEqual(r->left, s->left);
    }
};
