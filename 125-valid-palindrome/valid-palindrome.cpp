class Solution {
public:
    string transform(string & s ){
        string trans = "";
        for(char &c : s){
            if(c >= 'A' && c <= 'Z'){
                char newc = char(c-'A' + 'a');
               // cout << c << " "<<newc<<endl;
                trans += newc;
            }
            else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                trans += c;
            }
        }
        return trans;
    }

    bool isPalindrome(string s) {
       
        string transs = transform(s );
         int l = 0 , r = transs.length() - 1;
        while(l <= r){
            if(transs[l] != transs[r])return false;
            l++,r--;
        }
        return true;
    }
};