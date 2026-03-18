// reverse a stack
import java.util.Stack;

class reverse_A_stack{
    public static void insertAtBottom(Stack<Integer> s,int value){
        if(s.isEmpty()){
            s.push(value);
            return;
        }
        int topVal=s.peek();
        s.pop();
        insertAtBottom(s,value);
        s.push(topVal);
    };
    public static void reverseStack(Stack<Integer> s){
        if(s.isEmpty()){
            return;
        }
        int topValue=s.peek();
        s.pop();
        reverseStack(s);
        insertAtBottom(s,topValue);
    };
    public static void main(String[] args) {
        Stack <Integer> s= new Stack<>();
        
        s.push(10);
        s.push(20);
        s.push(30);
        
        reverseStack(s);
        
        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();
        }
    }
}