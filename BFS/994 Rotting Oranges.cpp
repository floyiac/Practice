class Solution {
    const int dx[4] = {1,0,0,-1};
    const int dy[4] = {0,1,-1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j] == 2){
                    q.emplace(i,j);
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int d=0;d<size;d++){
                auto [i,j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if(mx >=0 && my >= 0 && mx < row && my < column && grid[mx][my] == 1){
                        grid[mx][my] += 1;
                        q.emplace(mx,my);
                    }
                }
            }
            if(!q.empty()){
                ans += 1;
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};