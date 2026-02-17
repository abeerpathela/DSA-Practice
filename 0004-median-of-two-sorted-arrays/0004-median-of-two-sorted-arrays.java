class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;

        int total=m+n;

        int i=0;
        int j=0;

        int prev=0;
        int curr=0;

        for(int k=0; k<=total/2; k++){
            prev=curr;
            if(i<n && (j>=m || nums1[i]<=nums2[j])){
                curr=nums1[i];
                i++;
            }
            else{
                curr=nums2[j];
                j++;
            }
        }

        if(total%2==1){
            return curr;
        }
        else{
            return (prev+curr)/2.0;
        }
    }
}