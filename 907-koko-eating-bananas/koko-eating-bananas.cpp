class Solution {
public:
    bool valid(int mid , vector<int> & piles , int h){
        int cal = 0;
        for(int &i : piles){
            cal += ceil(i/double(mid));
            if(cal > h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 , end = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(valid(mid , piles, h))
            {
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};