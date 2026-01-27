class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int el = nums[mid];
            if(el == target)return mid;
            else if(el > target)end = mid-1;
            else start = mid + 1;
        }
        return -1;
    }
};