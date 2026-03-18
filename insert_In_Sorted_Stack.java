// insert in a sorted stack 
import java.util.Stack;

class insert_In_Sorted_Stack {
    public static void insertInSortedStack(Stack<Integer> s,int value){
        int topValue=s.peek();
        if(topValue<=value){
            s.push(value);
            return;
        }
        s.pop();
        insertInSortedStack(s,value);
        s.push(topValue);
    }
    public static void main(String[] args) {
        Stack<Integer> s=new Stack<>();
        
        s.push(10);
        s.push(20);
        s.push(40);
        
        insertInSortedStack(s,30);
        
        while(!s.isEmpty()){
            System.out.println(s.pop());
        }
        
    }
}