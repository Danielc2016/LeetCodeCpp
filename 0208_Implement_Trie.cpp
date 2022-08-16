class TrieNode{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto& c : word)
        {
            int k = c - 'a';
            if( cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        int k = 0;
        for(int i = 0; i < word.length(); i++)
        {
            k = word[i] - 'a';
            if(cur->children[k] == NULL)
                return false;
            cur = cur->children[k];
        }
        return cur && cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int k = 0;
        for(int i = 0; i < prefix.length(); i++)
        {
            k = prefix[i] - 'a';
            if(cur->children[k] == NULL)
                return false;
            cur = cur->children[k];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
