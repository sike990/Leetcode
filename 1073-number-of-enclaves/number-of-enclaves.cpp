class Solution {
public:
    void bfs(int  r, int c , vector<vector<int>> & valid , int n , int m , vector<vector<int>> & grid){

        if(valid[r][c] == 1)return;
        queue<pair<int,int>> q;
        q.emplace(r,c);
        valid[r][c] = 1;
        vector<vector<int>> trav = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto el = q.front();
            int ix = el.first , j = el.second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x = ix + trav[i][0];
                int y = j + trav[i][1];
                if((x > -1 && x < n) && (y > -1 && y < m) && grid[x][y] == 1 && valid[x][y] != 1){
                    valid[x][y] = 1;
                    q.emplace(x,y);
                }
            }
        }

        return;

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> valid(n , vector<int> (m , 0));
        for(int i  = 0; i < m ; i++){
           if(grid[0][i] == 1)bfs(0 , i , valid, n ,m , grid);
           if(grid[n-1][i] == 1)bfs(n-1 , i , valid , n ,m , grid);
        }
        for(int i  = 1; i < n-1 ; i++){
           if(grid[i][0] == 1)bfs(i , 0 , valid, n ,m , grid);
           if(grid[i][m-1] == 1)bfs(i , m-1 , valid, n ,m , grid);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && valid[i][j] == 0)count++;
            }
        }

        return count;
    }
};