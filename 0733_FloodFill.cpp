class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int pre = image[sr][sc];
        Filling(image, sr, sc, pre, color);
        return image;
        
    }
    
    void Filling(vector<vector<int>>& image,
                 int row,
                 int col,
                 int& pre,
                 int& color)
    {
        if( row < 0 || row >= image.size() ||
            col < 0 || col >= image[0].size() )
            return;
        if( image[row][col] != pre ||
            image[row][col] == color)
            return;
        //exit condition
        
        //operation
        image[row][col] = color;
        
        //four directions
        Filling(image, row-1, col, pre, color );
        Filling(image, row+1, col, pre, color );
        Filling(image, row, col-1, pre, color );
        Filling(image, row, col+1, pre, color );
    }
};
