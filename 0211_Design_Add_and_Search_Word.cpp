class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    
    TrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            int k = word[i] - 'a';
            if(cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        return helper(word, cur);
        
    }
private:
    TrieNode* root;
    bool helper(string word, TrieNode* cur)
    {
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i]!= '.')
            {
                int k = word[i] - 'a';
                if(!cur->children[k])
                    return false;
                cur = cur->children[k];
            }
            else
            {
                bool found = false;
                for(int j = 0; j < 26; j++)
                {
                    if(cur->children[j])
                        found |= helper(word.substr(i+1), cur->children[j]);
                }
                if(found)
                    return true;
                else
                    return false;
            }
        }
        return cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
