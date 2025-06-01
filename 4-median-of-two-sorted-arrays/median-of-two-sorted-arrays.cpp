class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() , m = nums2.size();
        if(n > m)return findMedianSortedArrays(nums2,nums1);
        int total = m+n , req = total/2;

        int s = 0 , e = n;

        while(s <= e){
            int mid = s + (e-s)/2;
            int mid1 = req-mid;

            int l1 = INT_MIN , l2 = INT_MIN , r1 = INT_MAX , r2 = INT_MAX;

            if(mid-1 >= 0)l1 = nums1[mid-1];
            if(mid < n)r1 = nums1[mid];
            if(mid1-1 >= 0 && mid1-1 < m)l2 = nums2[mid1-1];
            if(mid1 >= 0 && mid1 < m)r2 = nums2[mid1];

            if(l1 <= r2 && l2 <= r1){
                if(total&1)return min(r1,r2);
                else{
                    return (max(l1,l2)+min(r1,r2))/double(2);
                }
            }
            else if(l1 > r2)e = mid-1;
            else s = mid+1;

        }
        return -1;
    }
};