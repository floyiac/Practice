class Solution {
    //BFS
    int const dx[4] = {1,0,0,-1};
    int const dy[4] = {0,1,-1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int column = mat[0].size();
        vector<vector<int>> ans(row,vector<int>(column));
        vector<vector<int>> seen(row,vector<int>(column));
        queue<pair<int,int>> que;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    seen[i][j] = 1;
                    que.emplace(i,j);
                }
                else{
                    ans[i][j] = -1;
                    seen[i][j] = -1;
                }
            }
        }
        while(!que.empty()){
            auto [i,j] = que.front();
            que.pop();
            for(int k=0;k<4;k++){
                int mx = i + dx[k];
                int my = j + dy[k];
                if(mx >=0 && my>=0 && mx < row && my <column && seen[mx][my] == -1){
                    que.emplace(mx,my);
                    ans[mx][my] = 1 + ans[i][j];
                    seen[mx][my] = 1;
                }
            }
        }
        return ans;
    }
};