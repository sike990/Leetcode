class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size() , last = 0;
        for(int i = 0 ; i < n ; i++){
            if(i > last)return false;

            last = max(nums[i] + i , last);
            if(last >= n-1)return true;
        }
        return true;
    }
};