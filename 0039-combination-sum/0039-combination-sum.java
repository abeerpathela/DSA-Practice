class Solution {
    private void generate(int[] candidates,int target,int index,List<Integer> temp,List<List<Integer>> results){
        if(target == 0){
            results.add(new ArrayList<>(temp));
            return;
        }
        if(index == candidates.length){
            return;
        }
        if(candidates[index] <= target){
            temp.add(candidates[index]);
            generate(candidates,target - candidates[index],index,temp,results); // include
            temp.remove(temp.size()-1); // backtrack 
        }
        generate(candidates,target,index+1,temp,results); // skip the element (exclude)
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        generate(candidates,target,0,temp,results);
        return results;
    }
}