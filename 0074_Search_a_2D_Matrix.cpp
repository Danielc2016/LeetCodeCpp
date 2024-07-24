class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n;
        while( low < high )
        {
            int mid = low + (high -low)/2;
            int val = matrix[mid/n][mid%n];
            if( target == val )
            {
                return true;
            }
            else if( target < val )
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};
