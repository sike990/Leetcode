class Solution {
public:
    int sortPermutation(vector<int>& nums) {
 
        int  n = nums.size();
        int l = ceil(log(n)/log(2));
        int k = pow(2,l)-1;
        bool found = true;
        //following a property that a bitwise AND operations will always return a value <= {minimum of set of values on which the operation is performed}
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i){
            k = k&nums[i];
            found = false;
            //cout<<nums[i] << " " << k <<endl;
            }
        }
        if(found)return 0;
        return k;
    }
};