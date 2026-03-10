class Solution {
    private void generate(int open,int close,int n,String current,List<String> results){
        if(current.length() == n*2){
            results.add(current);
            return;
        }

        if(open<n){
            generate(open+1,close,n,current+"(",results);
        }

        if(close<open){
            generate(open,close+1,n,current+")",results);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> results= new ArrayList<>();
        generate(0,0,n,"",results);
        return results;
    }
}