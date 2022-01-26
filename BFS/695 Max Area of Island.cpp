class Solution {
    //BFS search
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x <0 || y <0 || x>=grid.size() || y>= grid[0].size() || grid[x][y] != 1){
            return 0;
        }
        grid[x][y] = 0;
        int ans = 1;
        for(int i=0;i<4;i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            ans += dfs(grid,mx,my);
        }
        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};