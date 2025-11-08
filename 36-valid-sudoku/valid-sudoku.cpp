class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        //setting up for column
        vector<vector<bool>> col(n, vector<bool>(9,false));
        //setting up for row
        vector<vector<bool>> row(n , vector<bool>(9,false));

        //setting up for the segments
        vector<vector<bool>> sec(n,vector<bool>(9,false));

        for(int i = 0  ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                char ch = board[i][j];
                if(ch == '.')continue;
                int seci = ((3)*(i/3))+(j/3);
                cout << i << j <<" "<< seci << endl;
                bool ncol = !col[i][ch - '1'];
                bool nrow = !row[j][ch-'1'];
                bool nsec = !sec[seci][ch - '1'];
                if(ncol && nrow && nsec){
                    col[i][ch - '1'] = true;
                    row[j][ch-'1'] = true;
                    sec[seci][ch - '1'] = true;
                }
                else{
                    return false;
                }
            }
        }

        return true;

    }
};