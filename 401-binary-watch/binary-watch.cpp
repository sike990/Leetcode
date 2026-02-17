class Solution {
public:
    vector<string> makehours(int n){
        if(n == 0)return {"0"};
        if(n == 1)return {"1","2","4","8"};
        if(n == 2)return {"3","5","6","9","10"};
        if(n == 3)return {"7","11"};
        return {};
    }
    bool havebits(int num,int bits){
        int count = 0;
        while(num){
            if(num&1)count++;
            num = num>>1;
        }
        return count == bits;
    }
    vector<string> makeminutes(int n){
        if(n == 0)return {"00"};
        vector<string> minutes;
        for(int i = 1 ; i <= 59 ; i++){
            if(havebits(i,n)){
                string curr;
                if(i <= 9){
                     curr = "0" + to_string(i);
                }
                else
                {
                    curr = to_string(i);
                }
                minutes.push_back(curr);
            }
        }
        return minutes;
    }
    vector<string> readBinaryWatch(int turnedon) {
        vector<string> ans;
        //Doing bits division for minutes and hour
        for(int i = 0 ; i <= turnedon ; i++){
            int hbits = i;
            int mbits = turnedon - i;
            vector<string> hours = makehours(hbits);
            vector<string> minutes = makeminutes(mbits);
            if(hours.size() == 0 || minutes.size() == 0)continue;
            for(int i = 0 ; i < hours.size() ; i++){
                string curr = hours[i];
                for(int j = 0 ; j < minutes.size() ; j++){
                    curr = curr + ":" + minutes[j];
                    ans.push_back(curr);
                    curr = hours[i];
                }
            }
        }
        return ans;
    }
};