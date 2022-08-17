//Hard
class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false)
    {
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* getRoot()
    {
        return root;
    }
    Trie( vector<string>& words )
    {
        root = new TrieNode();
        for(auto& ele:words)
        {
            addWord(ele);
        }
    }
    void addWord(string& word)
    {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            int k = word[i] - 'a';
            if( cur->children[k] == NULL)
                cur->children[k] = new TrieNode();
            cur = cur->children[k];
        }
        cur->isEnd = true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        string word = "";
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                walk(board, i, j, word, root, res);
        return res;
    }
    
    void walk(vector<vector<char>>& board, int i, int j,
              string word, TrieNode* cur, vector<string>& res)
    {
        //exit statement
        if( i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
          board[i][j] == '#')
            return;

        // base case
        int k = board[i][j] - 'a';
        if(cur->children[k])
        {
            cur = cur->children[k];
            auto c = board[i][j];
            word += board[i][j];
            // found word
            if(cur->isEnd)
            {
                res.push_back(word);
                cur->isEnd = false;
            }
            board[i][j] = '#';
            // four directions
            walk(board, i+1, j, word, cur, res);
            walk(board, i-1, j, word, cur, res);
            walk(board, i, j+1, word, cur, res);
            walk(board, i, j-1, word, cur, res);
            board[i][j] = c;
        }
    }
};

