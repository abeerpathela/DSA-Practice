// MIN-DIFFRENCE
import java.util.Arrays;
public class minDiffrence
{
    public static int minDiff(int [] arr){
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        return minDiff;
    }
	public static void main(String[] args) {
	    int[] arr={10,1,2,3,4,5};
		System.out.println(minDiff(arr));
	}
}