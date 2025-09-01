class Solution {
public:
    // int gcd(int a , int b){
    //     int lim = min(a,b);
    //     for(int i = lim ; i >= 1 ; i--){
    //         if(a%i + b%i == 0)return i;
    //     }
    //     return 1;
    // }
    // int count(int n , int c){

    //     int countel = 0;
    //     int el = 1;
    //     int sumel = 0;
    //     while(countel < n){
    //         if(el%2 == c){
    //             sumel += el;
    //             countel++;
    //         }
    //         el++;
    //     }
    //     return sumel;
    // }
    int gcdOfOddEvenSums(int n) {
        int sume = 0 , sumo = 0;

        sumo = n*n;
        sume = n*(n+1);
        if(sumo%n == 0)return n;
        return 1;
        //return gcd(sumo,sume);
    }
};