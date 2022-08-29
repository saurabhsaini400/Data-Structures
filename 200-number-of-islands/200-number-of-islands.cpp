class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '2' || grid[i][j] == '0')
            return;
       
      
        
     // visited 
        grid[i][j] = '2';
        
      
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
            int ans =0;
   
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
               
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                } 
            }
        }
        return ans;
    }
};
