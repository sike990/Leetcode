class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto s : strs){
            array<int,26> arr = {0};
            for(char &c : s){
                arr[c-'a']++;
            }
            string key = "";
            for(int i : arr){
                key += to_string(i)+'#';
            }
            mp[key].push_back(s);
            
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};