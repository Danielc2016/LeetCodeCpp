class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        bool res = false;
        vector<vector<int>> visited( maze.size(), vector<int>(maze[0].size(), 0));
        visited[start[0]][start[1]] = 1;
        vector<vector<int>> dirs_ = {{-1,0},{0,1},{1,0},{0,-1}};
        walk(maze, start[0], start[1], visited, dirs_, destination, res);
        return res;
    }
    

    void walk(vector<vector<int>>& maze, int i, int j,
              vector<vector<int>>& visited,
              vector<vector<int>>& dirs_,
              vector<int>& destination, bool& pass)
    {
        //exit statement
        // if(i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size() )
        //     return;
        if(i == destination[0] && j == destination[1] )
        {
            pass = true;
            return;
        }
        for(auto& ele : dirs_)
        {
            int x = i, y = j;
            while( x>=0 && x < maze.size() &&
               y >= 0 && y < maze[0].size() && !maze[x][y])
            {
                x += ele[0];
                y+=ele[1];
            }
            x-=ele[0];
            y-=ele[1];
            if(!visited[x][y])
            {
                visited[x][y] = 1;
                walk(maze, x, y, visited, dirs_, destination, pass);
            }
        }
    }
};
