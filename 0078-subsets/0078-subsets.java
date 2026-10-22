class Solution {
    List<List<Integer>> Answer=new ArrayList<>();
    private void generate(int[] nums, int index, List<Integer> current){
        Answer.add(new ArrayList<>(current));

        for(int i=index; i<nums.length; i++){
            current.add(nums[i]);
            generate(nums,i+1,current);
            current.remove(current.size()-1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> current= new ArrayList<>();
        generate(nums,0,current);
        return Answer;
    }
}