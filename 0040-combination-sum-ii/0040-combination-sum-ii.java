class Solution {
    private void generate(int[] candidates,int target,int index, List<Integer> temp, List<List<Integer>> results)   {
        if(target == 0){
            results.add(new ArrayList<>(temp));
            return;
        }
        if(index == candidates.length){
            return;
        }
        if(candidates[index] <= target){
            temp.add(candidates[index]);
            generate(candidates,target-candidates[index],index+1,temp,results);
            temp.remove(temp.size()-1);
        }
        int nextIndex=index+1;
        while(nextIndex < candidates.length && candidates[nextIndex]==candidates[index]){
            nextIndex++;
        }
        generate(candidates,target,nextIndex,temp,results);
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
       Arrays.sort(candidates);
       List<List<Integer>> results=new ArrayList<>();
       List<Integer> temp=new ArrayList<>();
       generate(candidates,target,0,temp,results);
       return results; 
    }
}