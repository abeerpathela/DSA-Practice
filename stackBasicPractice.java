// stack basic practice 
import java.util.Stack;
public class stackBasicPractice
{
	public static void main(String[] args) {
		Stack<Integer> s=new Stack<>();
		
		s.push(10);
		s.push(20);
		s.push(30);
		
		System.out.println(s.peek()); // it will print the top most element of the stack 
		
		System.out.println(s.pop()); // it will print and remove the top most element of the stack 
		
		System.out.println(s.peek());
		
		System.out.println(s.isEmpty()); // it will check the stack is empty or not 
		
		System.out.println(s.size()); // it will print the size of the stack 
	}
}