class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,vector<int>> indx;
        unordered_map<int,int> count;
        int n = nums.size();
        int ind = 0;
        for(int i : nums){
            count[i]++;
            indx[i].push_back(ind);
            ind++;
        }

        for(int i = 0 ; i <n ; i++){
            count[nums[i]]--;
            if(count[target-nums[i]] > 0){
                ans.push_back(i);
                for(int x : indx[target-nums[i]]){
                    if(x != i)
                    ans.push_back(x);
                }
               break;
            }
        }
        return ans;

    }
};