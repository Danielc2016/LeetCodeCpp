class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(0 == matrix[i][j])
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(unordered_set<int>::iterator it = row.begin(); it!= row.end(); it++)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[*it][i] = 0;
            }
        }
        for(unordered_set<int>::iterator it = col.begin(); it!= col.end(); it++)
        {
            for(int i = 0; i < m; i++)
            {
                matrix[i][*it] = 0;
            }
        }
        // while(!row.empty())
        // {
        //     int r = row.begin();
        //     row.erase(row.begin());
        //     for(int i = 0; i < n; i++)
        //     {
        //         matrix[r][i] = 0;
        //     }
        // }
    }
};
