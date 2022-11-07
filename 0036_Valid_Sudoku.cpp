class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = (int) board.size();
        vector<unordered_set<int>> rows(9), cols(9), blocks(9);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if( board[i][j] != '.')
                {
                    int temp = board[i][j] - '0';
                    int bIndex = 3* (i/3) + (j/3);
                    if(  rows[i].find(temp) != rows[i].end() 
                      || cols[j].find(temp) != cols[j].end()
                      || blocks[bIndex].find(temp) != blocks[bIndex].end() )
                        return false;
                    rows[i].insert(temp);
                    cols[j].insert(temp);
                    blocks[bIndex].insert(temp);
                }
            }
        }
        return true;
    }
};

/*
0 ,1, 2 | 3, 4, 5 |
0, 1, 2 | 3, 4, 5 |
0, 1, 2 | 3, 4, 5 |



block 0 [i/3][j/3] 
block 1 [i/3][j/3]

block 3 [i/3][j/3]
rows : 0 ~ 8 
cols : 0 ~ 8
9 + 9 + 9 hash table:


*/
