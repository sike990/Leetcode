class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int> dp(nums.size() , 0);
        int n = nums.size();
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2 ; i < n ; i++){
            int left = (i-3 >= 0)?dp[i-3]:INT_MIN;
            int right = dp[i-2];
            dp[i] = nums[i] + max(left , right);
        }

        return max(dp[n-1] , dp[n-2]);
    }
};