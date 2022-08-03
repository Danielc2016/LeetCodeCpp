class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        bool hasFound = false;
        //vector<char> path;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                Tracking(board, hasFound,
                 i, j, 0, word);
            }
        }
        return hasFound;
    }
    
    void Tracking(vector<vector<char>>& board,
                  //vector<char>& path,
                  bool& hasFound,
                  int row,
                  int column,
                  int count, //count the letter for string
                  string word)
    {
        if(count  == word.length())
        {
            hasFound = true;
            return;
        }
        int n = board.size(), m = board[0].size();
        if(   row < 0 || row >= n || 
              column < 0 || column >=m ||
              board[row][column] != word[count])
            return;
        
        board[row][column] = '0'; // mark as visited
        
        // 4 directions
        Tracking(board, hasFound,
                 row-1, column, count+1, word);
        Tracking(board, hasFound,
                 row+1, column, count+1, word);
        Tracking(board, hasFound,
                 row, column-1, count+1, word);
        Tracking(board, hasFound,
                 row, column+1, count+1, word);
        board[row][column] = word[count];
        // mark it back
    }
};
