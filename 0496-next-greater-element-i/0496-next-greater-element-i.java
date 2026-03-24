class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> s=new Stack<>();
        int i=0;
        while(i<nums1.length){
            int current=nums1[i];
            int j=0;
            int nextMax=current;
            int found=0;
            while(j<nums2.length){
                if(current==nums2[j]){
                    found=1;
                }
                if((nums2[j]>nextMax)&&(found==1)){
                    nextMax=nums2[j];
                    break;
                }
                j++;
            }
            if(nextMax==current){
                s.push(-1);
            }
            else{
                s.push(nextMax);
            }
            i++;
        }
        int[] results=new int[s.size()];
        int k=0;
        while(k<s.size()){
            results[k]=s.get(k);
            k++;
        }
        return results;
    }
}