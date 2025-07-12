class Solution {
public:
    int trap(vector<int>& rain) {
        int n = rain.size();

        vector<int> pref(n);
        pref[0] = rain[0];
        vector<int> suff(n);
        suff[n-1] = rain[n-1];
        for(int i = 1 ; i < n ; i++) pref[i] = max(pref[i-1],rain[i]);
        for(int i = n-2 ; i >= 0 ; i--) suff[i] = max(suff[i+1],rain[i]);
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            if(rain[i] < pref[i] && rain[i] < suff[i]){
                total += (min(pref[i],suff[i]))-rain[i];
            }
        }
        return total;
    }
};