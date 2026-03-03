class Solution {
    public void rotate(int[] nums, int k) {
        int[] temp=new int[k];
        int z=0;

        k=k%nums.length;

        for(int i=nums.length-k; i<nums.length; i++){
            temp[z]=nums[i];
            z++;
        }

        for(int i=nums.length-1; i>=0; i--){
            if(i-k>=0){
                nums[i]=nums[i-k];
            }
        }

        for(int cpy=0; cpy<z; cpy++){
            nums[cpy]=temp[cpy];
        }

    }
}