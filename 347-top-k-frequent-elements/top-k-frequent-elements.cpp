class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        vector<vector<int>> cnt(nums.size() + 1);
        for(int i = 0 ; i < nums.size() ; i++)mp[nums[i]]++;

        for(auto x : mp)cnt[x.second].push_back(x.first);

        for(int i = nums.size() ; i > 0 ; i--){
            for(auto x : cnt[i]){
                ans.push_back(x);
                if(ans.size()==k)return ans;
            }
        }

        return ans;
    }
};