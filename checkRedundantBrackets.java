// check redundant brackets 
import java.util.Stack;
class checkRedundantBrackets {
    public static boolean isRedundant(String str){
        Stack<Character> s = new Stack<>();
        
        for(int i=0; i<str.length(); i++){
            char topChar = str.charAt(i);
            if(topChar==')'){
                boolean hasOperator=false;
                if(s.isEmpty()){
                    return true;
                }
                while(!s.isEmpty() && s.peek()!='('){
                    char topValue=s.peek();
                    s.pop();
                    if(topValue=='+' || topValue=='-' || topValue=='*' || topValue=='/' ){
                        hasOperator=true;
                    }
                }
                if(!s.isEmpty()){
                    s.pop();
                }
                if(!hasOperator){
                    return true;
                }
            }
            else{
                s.push(topChar);
            }
        }
        return false;
    }
    public static void main(String[] args) {
        String str="((a+b))";
    }
}