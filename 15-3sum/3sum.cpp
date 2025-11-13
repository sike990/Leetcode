class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n-2 ; i++){
            int target = -nums[i];
            if(i > 0 && nums[i-1] == -target)continue;
            int r = n-1 , l = i+1;
            while(l < r){
                int curr = nums[l] + nums[r];
                if(curr == target){
                    ans.push_back({-target , nums[l] , nums[r]});
                    l++,r--;
                    while(l < r && nums[l] == nums[l-1])l++;
                    while(l < r && nums[r] == nums[r+1])r--;
                }
                else if(curr > target){
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};