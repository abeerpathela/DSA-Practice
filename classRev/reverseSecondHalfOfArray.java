// Reverse second half of the array 
public class reverseSecondHalfOfArray
{
	public static void main(String[] args) {
		int[] array={1,2,3,4,5};
		int halfInd=array.length/2;
		int size=array.length-1;
		while(halfInd<size){
		    int temp;
		    temp=array[halfInd];
		    array[halfInd]=array[size];
		    array[size]=temp;
		    
		    halfInd++;
		    size--;
		}
		for(int i=0; i<array.length; i++){
		    System.out.println(array[i]);
		}
	}
}