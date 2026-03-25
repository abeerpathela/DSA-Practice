// next greater element 
import java.util.Arrays;
import java.util.Stack;

public class nextGreaterElement
{
    public static int[] nextGreater(int[] arr){
        int[] result=new int[arr.length];
        Arrays.fill(result,-1);
        
        Stack<Integer> s=new Stack<>();
        
        for(int i=0; i<arr.length; i++){
            int current=arr[i];
            while(!s.isEmpty() && arr[s.peek()]<current){
                int index=s.pop();
                result[index]=current;
            }
            s.push(i);
        }
        return result;
    }
	public static void main(String[] args) {
		int[] arr={1,3,2,4};
		int[] result=nextGreater(arr);
		for(int i=0; i<result.length; i++){
		    System.out.print(result[i]+" ");
		}
	}
}