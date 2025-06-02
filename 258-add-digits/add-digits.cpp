class Solution {
public:
    int addDigits(int num) {
        
        while(num/10){
            int temp = num;
            int zer = 0;
            while(temp){
                int digit = temp%10;
                temp /= 10;
                zer += digit;
            }
            num = zer;
        }
        return num;
    }
};