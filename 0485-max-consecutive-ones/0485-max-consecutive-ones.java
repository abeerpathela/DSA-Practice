class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
       int count=0;
       int maxCount=0;
       for(int i=0; i<nums.length; i++) {
            if(nums[i]==1){
                count++;
            }
            else{
                maxCount=((count>maxCount)?count:maxCount);
                count=0;
            }
       }
       maxCount=((count>maxCount)?count:maxCount);
       count=0;
       return maxCount;
    }
}