class Solution {
public:
    void solve(int ind , int tar , vector<int> &candidates , vector<int> &temp , vector<vector<int>> &ans , int n){

                //base condition
                if(ind >= n || tar == 0){

                    if(tar == 0){
                    ans.push_back(temp);}

                    return;
                }


                for(int i = ind ; i < n ; i++){

                    if(tar - candidates[i] >= 0){
                        temp.push_back(candidates[i]);
                        solve(i , tar - candidates[i] , candidates ,temp , ans , n);
                        //backtrack
                        temp.pop_back();
                    }
                    else
                    {
                        return;
                    }
                }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(0,target,candidates,temp, ans , n);
        return ans;
    }
};