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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        DFS(root, 1, result);
        return result;
    }
    void DFS( TreeNode* root, int depth, vector<vector<int>>& res )
    {
        if(!root) return;
        if(depth > res.size())
            res.push_back({});
        res[depth-1].push_back(root->val);
        DFS(root->left, depth+1, res);
        DFS(root->right, depth+1, res);
    }
};
