class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>> q;
        int n = grid[0].size() , m = grid.size();
        int freshcount = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    pair<int,pair<int,int>> el = {0,{i,j}};
                    q.push(el);
                }
                else if(grid[i][j] == 1)freshcount++;
            }
        }

        if(!freshcount)return 0;//no fresh orange
        if(q.empty())return -1;//no rotten orange
        int time = -1;
        vector<vector<int>> vis(m , vector<int> (n , 0));
        vector<vector<int>> traversal = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        while(!q.empty()){

            auto topel = q.front();
            int currtime = topel.first;
            int r = topel.second.first;
            int c = topel.second.second;
            time = max(currtime , time);
            
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x = r + traversal[i][0];
                int y = c + traversal[i][1];
                if((x > -1 && x < m) && (y > -1 && y < n) && grid[x][y] == 1 && vis[x][y] == 0 ){   
                pair<int,pair<int,int>> el =  {currtime+1 , {x,y}};    
                q.push(el);
                vis[x][y] = 1;
                freshcount--;
                }
            }
        }

        return (freshcount == 0)?time:-1;

    }
};