class Solution {
    int count=0;
    public void generate(int[] nums,int goal, int index){
        int sum=0;
        for(int i=index; i<nums.length; i++){
            sum=sum+nums[i];
            if(sum==goal){
                count++;
            }  
        }
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
        count=0;
        for(int i=0; i<nums.length; i++){
            generate(nums,goal,i);
        }
        return count;
    }
}