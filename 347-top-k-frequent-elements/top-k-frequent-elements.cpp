class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i : nums)count[i]++;
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> bucket(n+1);
        for(auto i : count){
            bucket[i.second].push_back(i.first);
        }
        for(int i = n ;  i >= 0 ; i--){
        
            if(ans.size() >= k)break;

            for(auto x : bucket[i]){
                ans.push_back(x);
            }
            
        
    }
    return ans;
    }
};