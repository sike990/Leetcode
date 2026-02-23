class Solution {
public:
    // void make_bits(int n, unordered_map<string,int> &mp, int len, string &temp){
    //     if(len == n){
    //         mp[temp] = 1;
    //         return;
    //     }
    //     temp += "0";
    //     make_bits(n, mp, len+1, temp);
    //     temp.pop_back();
    //     temp += "1";
    //     make_bits(n, mp, len+1, temp);
    //     temp.pop_back();
    // }
    //it does not necessarily need to generate the substring beforehand we just need to count the unique substring

    bool hasAllCodes(string s, int k) {
        if((int)s.length() < k) return false;  // guard

        int limit = pow(2, k);
        unordered_map<string,bool> mp;
        //make_bits(k, mp, 0, temp);

        int count = 0;
        string win = s.substr(0,k);
        mp[win] = true;
        count++;
        for(int i = k; i < (int)s.length(); i++){
            win = win.substr(1) + s[i];
            if(mp.find(win) == mp.end()){
                count++;
                mp[win] = true;
            }
        }

        return (count == limit);
    }
};