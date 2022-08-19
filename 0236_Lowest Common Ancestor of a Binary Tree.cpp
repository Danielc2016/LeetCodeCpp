/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> father_map;
    unordered_set<TreeNode*> parent;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;
        father_map[root] = nullptr;
        DFS(root);
        TreeNode* temp = p;
        while( temp )
        {
            parent.insert(temp);
            temp = father_map[temp];
        }
        temp = q;
        while( temp )
        {
            if( parent.find(temp) != parent.end() )
            {
                return temp;
            }
            temp = father_map[temp];
        }
        return nullptr;
    }

    void DFS(TreeNode* root)
    {
        if(root->left)
        {
            father_map[root->left] = root;
            DFS(root->left);
        }
            
        if(root->right)
        {
            father_map[root->right] = root;
            DFS(root->right);
        }
    }
    
};
