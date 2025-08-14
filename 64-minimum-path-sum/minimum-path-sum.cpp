class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n , m;
        n  = grid.size() , m = grid[0].size();

        vector<int> prev(m , INT_MAX);
        prev[m-1] = 0;
        for(int i = n-1; i>= 0 ; i--){
            vector<int> curr(m);
            for(int j = m-1; j >= 0 ; j--){
                int right = INT_MAX;
                int down = prev[j];
                if(j+1 < m)right = curr[j+1];
                curr[j] = grid[i][j] + min(right , down);
            }
            prev = curr;
        }

        return prev[0];

    }
};