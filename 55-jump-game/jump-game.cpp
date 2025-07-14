class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        bool ans = false;
        int n = nums.size();
        vector<bool> dp(n , false);
        dp[n-1] = true;
        for(int i = n-2 ; i >= 0 ; i--){

            int el = nums[i];

            for(int j = 1 ; j+i < n && j <= el ; j++){
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};