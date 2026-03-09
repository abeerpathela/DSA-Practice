// Generate All Binary Strings 
import java.util.*;

public class generateAllBinaryStrings
{
    public static void generate(int n, String current,int previous,List<String> result){
        if(current.length() == n){
            result.add(current);
            return;
        }
        generate(n,current+"0",0,result);
        if(previous==0){
            generate(n,current+"1",1,result);
        }
    }
	public static void main(String[] args) {
		int n=3;
		List<String> result=new ArrayList<>();
		generate(n,"",0,result);
		System.out.println(result);
	}
}