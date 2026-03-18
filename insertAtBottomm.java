//Insert at bottom in stack 
import java.util.Stack;
class insertAtBottomm {
    public static void insertAtBottom(Stack<Integer> s,int value){
        if(s.isEmpty()){
            s.push(value);
            return;
        }        
        int topVal=s.peek();
        s.pop();
        insertAtBottom(s,value);
        s.push(topVal);
    }
    public static void main(String[] args) {
        Stack<Integer>s=new Stack<>();
        
        s.push(20);
        s.push(30);
        s.push(40);
        
        insertAtBottom(s,10);
        
        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();
        }
        
    }
}