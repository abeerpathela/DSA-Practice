// Is Stack sorted or not 

import java.util.Stack;
class stackIsSortedOrNot {
    public static boolean isSorted(Stack<Integer> s){
        if(s.size()<=1){
            return true;
        }
        int top1=s.peek();
        s.pop();
        int top2=s.peek();
        boolean answer=((top1>=top2)? (isSorted(s)): false);
        return answer;
    }
    public static void main(String[] args) {
        Stack<Integer> s=new Stack<>();
        
        s.push(10);
        s.push(20);
        s.push(90);
        s.push(40);
        
        System.out.println(isSorted(s));
    }
}