// Rotate array by k positions by left 
import java.util.Arrays;
public class RotateArrayByK
{
    public static int[] leftRotate(int[] array){
        int[] answer=new int[array.length];
        int ind=0;
        int ele=array[0];
        for(int i=1; i<array.length; i++){
            answer[ind]=array[i];
            ind++;
        }
        answer[ind]=ele;
        return answer;
    }
    public static int[] leftRotateByK(int[] array,int k){                       
        int[] finalAnswer = Arrays.copyOf(array, array.length);
        for(int i=1; i<=k; i++){
            finalAnswer=leftRotate(finalAnswer );
        }
        return finalAnswer;
    }
	public static void main(String[] args) {
		int[] array={1,2,3,4,5};
		int k=2;
		int[] result=leftRotateByK(array,k);
		for(int i=0; i<result.length; i++){
		    System.out.println(result[i]);
		}
	}
}