class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin() , matrix.end());
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(i < j)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};