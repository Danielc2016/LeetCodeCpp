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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        auto p = dfs(root, res);
        return res;
    }
    // <increasing, decreasing>
    pair<int, int> dfs(TreeNode* root, int& res)
    {
        if(!root) return {0, 0};
        pair<int, int> left = dfs(root->left, res);
        pair<int, int> right = dfs(root->right, res);
        int inc = 1, dec = 1;
        if(root->left)
        {
            if(root->left->val + 1 == root->val)
                inc += left.first;
            if(root->left->val - 1 == root->val)
                dec += left.second;
        }
        if(root->right)
        {
            if(root->right->val + 1 == root->val)
                inc = max(inc, right.first + 1);
            if(root->right->val - 1 == root->val)
                dec = max(dec, right.second + 1); 
        }
        res = max(res, inc + dec -1);
        return {inc, dec};
    }
};
