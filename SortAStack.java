// sort a stack 
import java.util.Stack;
import java.util.*;
public class SortAStack
{
    public static Stack<Integer> sortStack(Stack<Integer> stack){
        Stack<Integer>temp=new Stack<>();
        while(!stack.isEmpty()){
            int current=stack.pop();
            while(!temp.isEmpty() && temp.peek()<current){
                stack.push(temp.pop());
            }
            temp.push(current);
        }
        return temp;
    }
	public static void main(String[] args) {
		Stack<Integer>stack=new Stack<>();
		
		stack.push(4);
		stack.push(1);
		stack.push(3);
		stack.push(2);
		
		Stack<Integer>answer=sortStack(stack);
		Iterator<Integer>it=answer.iterator();
		while(it.hasNext()){
		    int current=it.next();
		    System.out.println(current);
		}
	}
}