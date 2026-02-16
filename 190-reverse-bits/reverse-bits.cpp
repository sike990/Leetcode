class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 31 ; i >= 0 ; i--){
            if(n&1){
                ans += pow(2,i);
            }
            n>>=1;
        }
        return ans;
    }
};