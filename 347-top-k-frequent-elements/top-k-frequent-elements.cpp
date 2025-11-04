class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i : nums)count[i]++;
        int n = nums.size();
        vector<int> ans;

        priority_queue<pair<int,int>> pq;
        for(auto i : count){
            pq.emplace(i.second , i.first);
        }

        while(k-- &&  !pq.empty()){
                auto front = pq.top();
                ans.push_back(front.second);
                pq.pop();
        }
    return ans;
    }
};