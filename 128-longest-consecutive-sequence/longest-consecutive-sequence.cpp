class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums)s.insert(i);
        int maxlen = 0;
        for(auto i : s){
            if(s.find(i-1) != s.end())continue;
            else if(s.find(i-1) == s.end()){
                int len = 0;
                int x = i;
                while(s.find(x) != s.end()){
                    len++;
                    x++;
                }
                maxlen = max(len , maxlen);
            }
            
        }
        return maxlen;
    }
};