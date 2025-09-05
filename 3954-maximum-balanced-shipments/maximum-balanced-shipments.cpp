class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count = 0;
        int elcount = 0;
        int currmax = INT_MIN , n = weight.size();
        for(int i = 0 ; i < n ; i++){
            elcount++;
            currmax = max(weight[i],currmax);
            if(elcount > 1 && weight[i] < currmax){
                count++;
                elcount = 0;
                currmax = INT_MIN;
            }
            
        }
        return count;
    }
};