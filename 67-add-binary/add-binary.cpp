class Solution {
public:
    string addBinary(string a, string b) {
        if(b.length() > a.length()){return addBinary(b,a);
}
        int diff = a.length()-b.length();
        for(int i = 0 ; i < diff ; i++){
            b = "0" + b;
        }

        int i = b.length()-1;
        string ans = "";
        bool carry=false;
        while(i >= 0){
            string curr;
            if(b[i] == '1' && a[i] == '1'){
                if(carry){
                    curr = "1";
                }
                else{
                    curr = "0";
                    carry = 1;
                }
            }
            else if(b[i] == '0' && a[i] == '0'){
                if(carry){
                    curr = "1";
                    carry = 0;
                }
                else{
                    curr = "0";
                }
            }
            else{
                if(carry){
                    curr = "0";
                }
                else{
                    curr = "1";
                }
            }
            ans = curr + ans;
            i--;
        }
        if(carry){
            ans = "1" + ans;
            carry = false;
        }
        return ans;
    }
};