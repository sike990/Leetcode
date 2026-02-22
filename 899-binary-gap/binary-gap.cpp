class Solution {
public:
    int binaryGap(int n) {
        int x = n;
        int dis = 0;
        bool one = false;
        int temp = 0;
        while(x)
        {
            
            if(x&1 && one){
                dis = max(temp,dis);
                temp = 0;
            }
            else if(x&1 && one == false){
                one = true;
            }
            if(one){
                temp++;
            }
            x >>= 1;
        }

        return dis;

    }
};