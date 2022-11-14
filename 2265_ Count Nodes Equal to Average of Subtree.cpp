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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        auto temp = dfs(root, res);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root, int& res)
    {
        if(!root)
            return {0, 0}; //Sum of nodes, number of nodes
        auto left = dfs(root->left, res);
        int leftSum = left.first, leftNode = left.second;
        auto right = dfs(root->right, res);
        int rightSum = right.first, rightNode = right.second;
        int totalNodes = leftNode + rightNode + 1;
        if( root->val == (root->val + leftSum + rightSum) / totalNodes )
            res++;
        return {root->val + leftSum + rightSum, totalNodes};
    }
};

/*


*/
