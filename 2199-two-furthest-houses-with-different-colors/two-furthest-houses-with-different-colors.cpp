class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int h = 0 ;  h < n ; h++){
            for(int i = n-1 ; i >= h ; i--){
                if(colors[h] != colors[i]){
                    ans = max(ans , i-h);
                }
            }
        }
        return ans;
    }
};