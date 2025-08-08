class Solution {
public:
    // bool solve(vector<int> &coins , int amount , int & n , int &ans , int temp){

    //     if(amount == 0){
    //         ans  = temp;
    //         return true;
    //     }
        
    
    //     for(int i = n-1 ; i >= 0 ; i--){
    //         if(amount >= coins[i]){
    //             int rem = amount/coins[i];
    //             bool found = solve(coins , amount - (rem*coins[i]) ,n , ans , temp+rem);
    //             if(found)return true;
    //         }
    //     }

    //     return false;
    // }
    int coinChange(vector<int>& coins, int sum) {
        
    vector<int> steps(sum+1 , 1e6);
	steps[0] = 0;

	//way 1
	//dp[k] = minimum no of steps to reach k 
	for(int i = 1 ; i <= sum ; i++){
		for(int &j : coins){
			if(i - j >= 0){
				steps[i] = min(steps[i] , steps[i-j] + 1);
			}
		}
	}
	int ans = (steps[sum] == 1e6)?-1:steps[sum];
	return ans;
    }
};