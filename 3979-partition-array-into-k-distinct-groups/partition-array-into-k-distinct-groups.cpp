class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n%k != 0)return false; //case where there are left over elements
        unordered_map<int,int> freq;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }
        int total_group = n/k;

        //discard the possiblty if the frequency of any element is greater than the total number of groups
        for(auto i : freq){
            if(i.second > total_group)return false;
        }

        return true;
    }
};