class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        int size=s.length();
        if(size%2!=0){
            return false;
        }
        char[] allOpen={'(','{','['};

        for(int i=0; i<s.length(); i++){
            char ch=s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.isEmpty()){
                    return false;
                }
                char topValue=st.peek();
                if(ch==')' && topValue!='('){
                    return false;
                }
                else if(ch=='}' && topValue!='{'){
                    return false;
                }
                else if(ch==']' && topValue!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.isEmpty()){
            return true;
        }
        return false;
    }
}