class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image[0].size() , m = image.size();
        queue<pair<int,int>> q;
        q.emplace(sr,sc);

        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[sr][sc] = 1;
        while(!q.empty()){
            
            auto topel = q.front();
            int u = topel.first;
            int v = topel.second;

            for(int i = 0 ; i < 4 ; i++){
                int x = u + dir[i][0];
                int y = v + dir[i][1];
                if((x >= 0 && x < m) && (y >= 0 && y < n) && (vis[x][y] != 1) && (image[u][v] == image[x][y])){
                    q.emplace(x,y);
                    vis[x][y] = 1;
                }
            }
            image[u][v] = color;
            q.pop();
        }


        return image;
    }
};