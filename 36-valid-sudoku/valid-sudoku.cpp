class Solution {
public:
    int findit(int &x , int &y){
        if(x >= 0 && x <= 2){
            if(y >= 0 && y <= 2)return 0;
            if(y >= 3 && y <= 5)return 1;
            if(y >= 6 && y <= 8)return 2;
        }
        if(x >= 3 && x <= 5){
            if(y >= 0 && y <= 2)return 3;
            if(y >= 3 && y <= 5)return 4;
            if(y >= 6 && y <= 8)return 5;
        }
        if(x >= 6 && x <= 8){
            if(y >= 0 && y <= 2)return 6;
            if(y >= 3 && y <= 5)return 7;
            if(y >= 6 && y <= 8)return 8;
        }
        return 0;
    }
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
                int seci = findit(i,j);
                //cout << ch <<" " << int(ch - '1') << endl;
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