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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }
    int DFS(TreeNode* root, int& maxSum)
    {
        if(!root) return 0;
        int left = DFS(root->left, maxSum);
        left = max(0, left);
        int right = DFS(root->right, maxSum);
        right = max(0, right);
        maxSum = max(root->val+left+right, maxSum);
        return root->val+max(left, right);
    }
};
