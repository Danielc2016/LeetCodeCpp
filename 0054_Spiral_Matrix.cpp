class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int left = 0, right = n - 1;
        int top = 0, bottom = m -1;
        while( left <= right && top <= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            if( ++top > bottom)
                break;
            for(int j = top; j <= bottom; j++)
            {
                res.push_back(matrix[j][right]);
            }
            if( --right < left)
                break;
            for(int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            if( --bottom < top)
                break;
            for(int j = bottom; j >= top; j--)
            {
                res.push_back(matrix[j][left]);
            }
            if( ++left > right)
                break;
        }
        return res;
    }
};
