class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int size=nums.length;
        int[] result=new int[size];
        Arrays.fill(result,-1); 

        Stack <Integer> s = new Stack<>();

        for(int i=0; i<2*size; i++){ // this loop condition for having a circular traversal across the array 
            int current=nums[i%size];
            while(!s.isEmpty() && nums[s.peek()]<current){
                int index=s.pop();
                result[index]=current;
            }
            if(i<size){
                s.push(i);
            }
        }

        return result;
    }
}