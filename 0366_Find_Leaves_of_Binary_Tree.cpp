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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, res);
        return res;
    }
    
    int DFS(TreeNode* root, vector<vector<int>>& res)
    {
        if(!root) return 0;
        int leftHeight = DFS(root->left, res);
        int rightHeight = DFS(root->right, res);
        int currHeight = max(leftHeight, rightHeight) + 1;
        if(currHeight > res.size())
        {
            res.push_back({});
        }
        res[currHeight-1].push_back(root->val);
        return currHeight;
    }
};
