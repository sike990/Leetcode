class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp(27,0);
        for(char c : s)mp[c - 'a']++;
        for(char d : t)mp[d - 'a']--;
        for(int i : mp)if(i != 0)return false;
        return true;
    }
};