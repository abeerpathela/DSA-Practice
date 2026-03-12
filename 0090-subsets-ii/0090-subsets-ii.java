class Solution {
    private void generate(int[] nums,int index,List<Integer> current,List<List<Integer>> results){
        results.add(new ArrayList<>(current));
        for(int i=index; i<nums.length; i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            else{
                // include 
                current.add(nums[i]);
                generate(nums,i+1,current,results);
                // backtrack 
                current.remove(current.size()-1);
            }
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> current = new ArrayList<>();
        List<List<Integer>> results= new ArrayList<>();
        generate(nums,0,current,results);
        return results;
    }
}