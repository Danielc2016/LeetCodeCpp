/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root) return "N,";
        string res = "";
        res += (to_string(root->val) + ",");
        string left = serialize(root->left);
        string right = serialize(root->right);
        res += (left + right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        queue<string> q;
        string temp = "";
        for(int i = 0; i < data.length(); i++)
        {
            if(data[i] == ',')
            {
                q.push(temp);
                temp = "";
                continue;
            }
            temp += data[i];
        }
        TreeNode* res = deserializeDFS(q);
        return res;
    }
    
    TreeNode* deserializeDFS( queue<string> &q )
    {
        string f = q.front();
        q.pop();
        if( f == "N")
            return NULL;
        TreeNode* root = new TreeNode(stoi(f));
        root->left = deserializeDFS(q);
        root->right = deserializeDFS(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
