class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , -1);
        for(int i = 0 ; i < n ; i++){
            int el = nums[i];
            int idx = (i+1)%n;
            while(true){
                if(nums[idx] > el){
                    ans[i] = nums[idx];
                    break;
                }
                idx = (idx+1)%n;
                if(idx == i)break;
            }
        }
        return ans;
    }
};