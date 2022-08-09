//DFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node)
    {
        if(!node) return NULL;
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node->val, {});
            for(auto n : node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(n));
        }
        return mp[node];
    }
};


//BFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//BFS
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node)
    {
        if(!node) return NULL;
        queue<Node*> nq;
        mp[node] = new Node(node->val, {});
        nq.push(node);
        while(!nq.empty())
        {
            auto tp = nq.front();
            nq.pop();
            for(auto nei : tp->neighbors)
            {
                if(mp.find(nei)==mp.end())
                {
                    mp[nei] = new Node(nei->val, {});
                    nq.push(nei);
                }
                mp[tp]->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
};


