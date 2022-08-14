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
//iterative approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int d = 0;
        if(!root) return d;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            d++;
        }
        return d;
    }
};
