class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int M = board.size(), N = board[0].size();
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(board[i][j] == 'X')
                {
                    res++;
                    dfs(board, i, j);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        if( row < 0 || row >= board.size() || col < 0 || col >= board[0].size() 
            || board[row][col] == '.' )
            return;
        board[row][col] = '.';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
};

/*

BFS / DFS


*/
