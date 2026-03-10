// Power Set 
import java.util.*;
import java.util.Scanner;
public class PowerSet
{
    public static void generate(int index,String current,String s,List<String> results){
        if(index == s.length()){
            if(!current.equals("")){
                results.add(current);
            }
            return;
        }
        // include 
        generate(index+1,current+s.charAt(index),s,results);
        // exclude 
        generate(index+1,current,s,results);
    }
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
		List<String> results=new ArrayList<>();
		String s;
		s=sc.nextLine();
		generate(0,"",s,results);
		Iterator<String>it=results.iterator();
		while(it.hasNext()){
		    System.out.println(it.next());
		}
	}
}