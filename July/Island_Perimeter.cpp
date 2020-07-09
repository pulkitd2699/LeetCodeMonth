// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            grid[i].push_back(0);
            grid[i].insert(grid[i].begin(),0);
        }
        vector<int> temp(grid[0].size(),0);
        grid.push_back(temp);
        grid.insert(grid.begin(), temp);
        
        int n = grid.size();
        int m = grid[0].size();
        
        int peri = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) peri += (grid[i][j-1] == 0) + (grid[i][j+1] == 0) + (grid[i-1][j] == 0) +                       (grid[i+1][j] == 0);
            }
        }
        return peri;
    }
};