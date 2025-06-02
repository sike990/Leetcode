class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size()  , n = nums2.size();
        int total = n+m;
        if(n < m)return findMedianSortedArrays(nums2,nums1);

        int req = (n+m)/2;

        int s = 0 , e = m;

        while(s <= e){
            int mid1 = s+(e-s)/2;

            int mid2 = req - mid1;

            int l1 = (mid1 > 0)?nums1[mid1-1]:INT_MIN;
            int l2 = (mid2 > 0)?nums2[mid2-1]:INT_MIN;
            int r1 = (mid1 < m)?nums1[mid1]:INT_MAX;
            int r2 = (mid2 < n)?nums2[mid2]:INT_MAX;

            if(l1 <= r2 && l2 <= r1)return (total&1)?min(r1,r2):((max(l1,l2)+min(r1,r2))/double(2));
            else if(l1 > r2)e = mid1-1;
            else s = mid1+1;
        }
        return -1;
    }   
};