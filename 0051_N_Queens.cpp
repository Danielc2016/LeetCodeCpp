class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        Tracking(res, board, 0);
        return res;
    }
    
    void Tracking(vector<vector<string>>& res, vector<string>& board,
                  int row)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        for(int i = 0; i < board.size(); i++)
        {
            if(isValid(board, row, i))
            {
                board[row][i] = 'Q';
                Tracking(res, board, row + 1);
                board[row][i] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& board, int row, int col)
    {
        //check
        for(int i = row; i >= 0; i--)
        {
            if(board[i][col] == 'Q')
                return false;
        }
        for(int i = row, j = col; i >=0 && j>=0; i--, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row, j = col; i >=0 && j<board.size(); i--, j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

