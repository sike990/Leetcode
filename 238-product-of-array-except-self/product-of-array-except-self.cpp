class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        vector<int> pref(n) , suff(n);
        pref[0] = 1 , suff[n-1] = 1;
        for(int i = 1 ; i < n ; i++){
            pref[i] = nums[i-1]*pref[i-1];
            suff[n-i-1] = suff[n-i]*nums[n-i];
        }
        for(int i = 0 ; i < n ; i++)ans[i] = pref[i]*suff[i];
        return ans;
    }
};