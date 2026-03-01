class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> track(3,-1);
        int e = 0;
        int ans = 0;
        while(e < n){
            int ind = s[e] - 'a';
            track[ind] = e;
            e++;
            int minind = *min_element(track.begin(),track.end());
            if(minind != -1){
                ans += minind+1;
            }
        }
        //logic we are adding the number of valid substring that can be formed upto current index having the value of the last minimum point including and before which all substring will be counted;
        return ans;
    }
};