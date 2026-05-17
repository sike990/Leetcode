class Solution {
public:
    bool check(vector<int> & num , int n , int rem , unordered_map<int,int> & mp){
        bool ans = false;
        for(int i : num){
            
            if(i%2 != rem){
                if(rem == 1 && mp[i] == 0){
                    return false;
                }
                else if(rem == 0 && mp[i] == 0){
                    return false;
                }
            }
            
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();
        vector<int> arr(nums1);
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int even = 0;


        for(int i = 0; i < n ; i++){
            mp[arr[i]] = even;
            if((arr[i]&1) == 1)
            even = 1;
        }
        //odd vector
        bool pos = check(nums1,n,1,mp);
        if(pos)
        return true;
        pos = check(nums1,n,0,mp);
        if(pos)
        return true;
        
        return false;
    }
};