class Solution {
    //BFS: queue implementation
public:
    const int dx[4] = {1,0,0,-1};
    const int dy[4] = {0,1,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> que;
        int Curr_color = image[sr][sc];
        if(Curr_color == newColor){
            return image;
        }
        int column = image[0].size();
        int row = image.size();
        que.emplace(sr,sc);
        image[sr][sc] = newColor;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int i=0;i<4;i++) {
                int x_value = x + dx[i];
                int y_value = y + dy[i];
                if (x_value >= 0 && x_value <= row - 1 && y_value >= 0 && y_value <= column - 1 &&
                    image[x_value][y_value] == Curr_color) {
                    image[x_value][y_value] = newColor;
                    que.emplace(x_value, y_value);
                }
            }
        }
        return image;
    }
};