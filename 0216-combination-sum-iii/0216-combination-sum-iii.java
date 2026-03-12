class Solution {
    private void generate(int start, int k, int sum, List<Integer> current, List<List<Integer>> results){
        if(k==0 && sum == 0){
            results.add(new ArrayList<>(current));
            return;
        }
        if(k==0 || sum==0){
            return;
        }
        for(int i=start ; i<=9; i++){
            current.add(i);
            generate(i+1,k-1,sum-i,current,results);
            current.remove(current.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> results= new ArrayList<>();
        List<Integer> current= new ArrayList<>();
        generate(1,k,n,current,results);
        return results;
    }
}