// subset sum (sum of all subsets)
import java.util.*;
import java.util.Iterator;
public class subsets1
{
    public static void generate(int[] arr,int n,int sum,int index,List<Integer> results){
        if(index == n){
            results.add(sum);
            return;
        }
        generate(arr,n,sum+arr[index],index+1,results);
        generate(arr,n,sum,index+1,results);
    } 
	public static void main(String[] args) {
		int[] arr={5,2,1};
		int n=3;
		List<Integer> results=new ArrayList<>();
		generate(arr,n,0,0,results);
		Iterator<Integer> it=results.iterator();
		while(it.hasNext()){
		    System.out.println(it.next());
		}
	}
}