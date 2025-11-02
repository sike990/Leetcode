class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;

        for(auto s : strs){
            string sort_str  = s;
            sort(sort_str.begin() , sort_str.end());
            mp[sort_str].push_back(s);
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};