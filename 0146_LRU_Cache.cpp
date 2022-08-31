class Node {
public:
    int key;
    int val;
    Node *left;
    Node *right;
    Node() : left(NULL), right(NULL) {}
    Node(int x, int y) : key(x), val(y), left(NULL), right(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        start->right = end;
        end->left = start;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            Node* temp = mp[key];
            int res = temp->val;
            deleteNode(temp);
            mp.erase(key);
            addNode(temp);
            mp[key] = start->right;
            return res;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end())
        {
            Node* temp = mp[key];
            if(temp->val != value)
            {
                temp->val = value;
            }
            deleteNode(temp);
            addNode(temp);
            mp.erase(key);
            mp[key] = start->right;
        }
        else
        {
            if(mp.size() < cap)
            {
                Node* newNode = new Node(key, value);
                addNode(newNode);
                mp[key] = newNode;
            }
            else if(mp.size() == cap)
            {
                Node* delNode = end->left;
                int delKey = delNode->key;
                mp.erase(delKey);
                deleteNode(delNode);
                Node* newNode = new Node(key, value);
                addNode(newNode);
                mp[key] = newNode;
            }
        }
        
    }
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* start = new Node();
    Node* end = new Node();
    
    void addNode(Node* newNode) {
        Node* temp = start->right;
        newNode->right = temp;
        newNode->left = start;
        start->right = newNode;
        temp->left = newNode;
    }
    
    void deleteNode(Node* nod) {
        Node* delPrev = nod->left;
        Node* delNext = nod->right;
        delPrev->right = delNext;
        delNext->left = delPrev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
