class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n  = numbers.size();
        int lef = 0 , rig = n-1;

        while(lef < rig){
            int curr = numbers[lef] + numbers[rig];
            if(curr == target)return {lef+1,rig+1};
            else if(curr > target)rig--;
            else lef++;
        }
        return {};
    }
};