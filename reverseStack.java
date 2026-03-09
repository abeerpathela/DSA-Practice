// Reverse a stack 
import java.util.Stack;
import java.util.*;
public class reverseStack
{
    private static void insertAtBottom(Stack<Integer> stack,int val){
        if(stack.isEmpty()){
            stack.push(val);
            return;
        }
        int top=stack.pop();
        insertAtBottom(stack,val);
        stack.push(top);
    }
    public static Stack<Integer> reverseStackk(Stack<Integer> stack){
        if(stack.isEmpty()){
            return stack;
        }
        int top=stack.pop();
        reverseStackk(stack);
        insertAtBottom(stack,top);
        return stack;
    }
	public static void main(String[] args) {
		Stack<Integer>stack=new Stack<>();
		stack.push(4);
		stack.push(1);
		stack.push(3);
		stack.push(2);
		Stack<Integer>answer=reverseStackk(stack);
		Iterator<Integer>it=answer.iterator();
		while(it.hasNext()){
		    System.out.println(it.next());
		}
	}
}