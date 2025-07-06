class Solution {
public:
    void dfs(vector<vector<char>> &board , vector<vector<int>> & vis , int r , int c , int m , int n){
        
        if(vis[r][c] == 1)return;
        vector<vector<int>> traversal = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[r][c] = 1;
        for(int i = 0 ; i < 4 ; i++){

            int x = r + traversal[i][0];
            int y = c + traversal[i][1];

            if((x > -1 && x < m) && (y > -1 && y < n) && board[x][y] == 'O' && vis[x][y] == 0){
                dfs(board , vis , x , y , m , n);
            }
            
        }


    }
    void solve(vector<vector<char>>& board) {
        int m = board.size() ,n =  board[0].size();
        vector<vector<int>> vis( m , vector<int> (n , 0));
            
            //for rows
            for(int i = 0 ; i < n ; i++){
                if(board[0][i] == 'O')dfs(board , vis , 0 , i , m , n);
                if(board[m-1][i] == 'O')dfs(board , vis , m-1 , i , m , n);
            }

            for(int i = 1 ; i < m-1 ; i++){
                if(board[i][0] == 'O')dfs(board , vis , i , 0 , m , n);
                if(board[i][n-1] == 'O')dfs(board , vis , i ,n-1 , m , n);
            }
            
            
            for(int i = 0 ; i < m-1 ; i++){
                for(int j = 1 ; j < n-1 ;  j++){
                    if(board[i][j] == 'O' && vis[i][j] == 0){
                        board[i][j] = 'X';
                    }
                }
            }
    }
};