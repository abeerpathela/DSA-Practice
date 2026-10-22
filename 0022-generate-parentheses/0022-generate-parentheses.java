class Solution {
    private void generate(int open, int close , int n, String current, List<String> Answer){
        if(current.length() == n*2){
            Answer.add(current);
        }

        if(open<n){
            generate(open+1,close,n,current+"(",Answer);
        }

        if(close<open){
            generate(open,close+1,n,current+")",Answer);
        }    
    }
    public List<String> generateParenthesis(int n) {
        List<String>Answer = new ArrayList<>();
        generate(0,0,n,"",Answer);
        return Answer;
    }
}