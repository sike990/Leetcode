class Solution {
public:
    int numberOfSubstrings(string str) {
        unordered_map<char,int> mp;
        int s = 0 , e = 0;
        int n = str.length();
        int count = 0;
        int ans = 0;
        while(s <= e){
            while(e < n && count < 3){
                if(mp[str[e]] == 0)
                count++;
                mp[str[e]]++;
                e++;
                //if(e >= n)break;
            }
            if(e >= n && count != 3)break;
            //int len = e-s;
            int remlen = n-e;
            ans += remlen+1;
            //cout << e << endl;
            mp[str[s]]--;
            if(mp[str[s]] < 1)count--;
            s++;
        }
        return ans;
    }
};