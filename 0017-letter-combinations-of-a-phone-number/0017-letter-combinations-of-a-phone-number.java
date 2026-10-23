class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result= new ArrayList<>();
        if(digits.length()==0){
            return result;
        }

        String[] map={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        backtrack(digits,0,new StringBuilder(),result,map);

        return result;
    }
    private void backtrack(String digits, int index, StringBuilder current, List<String> result, String[] map ){

        // Base Case ko handle karne ke liye 
        if(index == digits.length()){
            result.add(current.toString());
            return;
        }
        
        // Get the current string from the number ( 2 - "abc" )
        String letters= map[digits.charAt(index)-'0'];

        // loop on the characters ['a','b','c'] 
        for(char ch: letters.toCharArray()){
            current.append(ch);

            backtrack(digits,index+1,current, result, map);

            current.deleteCharAt(current.length() - 1);
        }
    }
}