import java.util.Arrays;
import java.util.Stack;
public class nextSmallerElement
{
    public static int[] nextSmaller(int[] arr){
        int[] result=new int[arr.length];
        Arrays.fill(result,-1);
        
        Stack<Integer>s=new Stack<>();
        
        for(int i=0; i<arr.length; i++){
            int current=arr[i];
            while(!s.isEmpty() && arr[s.peek()]>current){
                int index=s.pop();
                result[index]=current;
            }
            s.push(i);
        }
        
        return result;
    }
	public static void main(String[] args) {
		int[] nums={4,8,5,2,25};
		int[] result=nextSmaller(nums);
		for(int i=0; i<result.length; i++){
		    System.out.print(result[i]+" ");
		}
	}
}