class Solution {
public:
    vector<vector<bool> > aOcean, pOcean;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        aOcean = pOcean = vector<vector<bool>>(m, vector<bool>(n, false));
        
        //fix this part to start from the ocean
        for(int i = 0; i < m; i++)
        {
            walk(heights, i, 0, 0, res, pOcean);
            walk(heights, i, n-1, 0, res, aOcean);
        }
        for(int j = 0; j < n; j++)
        {
            walk(heights, 0, j, 0, res, pOcean);
            walk(heights, m-1, j, 0, res, aOcean);
        }
        return res;
    }
    
    void walk(vector<vector<int>>& heights, int i, int j, int pHeight,
              vector<vector<int>>& res, vector<vector<bool>>& visited )
    {
        //exit statement
        if( i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()
          || pHeight > heights[i][j] || visited[i][j] )
            return;
        //base case
        visited[i][j] = true;
        if(pOcean[i][j] && aOcean[i][j])
            res.push_back(vector<int>{i, j});
        //four directions

        int h = heights[i][j];
        walk(heights, i+1, j, h, res, visited);
        walk(heights, i-1, j, h, res, visited);
        walk(heights, i, j+1, h, res, visited);
        walk(heights, i, j-1, h, res, visited);
    }
};
