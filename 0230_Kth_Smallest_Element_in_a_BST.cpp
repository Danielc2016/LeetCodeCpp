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
//iterative solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        if(!root) return -1;
        stack<TreeNode*> s;
        //s.push(root);
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(--k == 0)
                return root->val;
            root = root->right;
        }
        return -1;
    }
};


