// count subsets 

public class countSubsets
{
    public static int countSubsequences(int index,int sum,int[] originals,int k){
        if(index == originals.length){
            if(sum == k){
                return 1; // this is to show subsequence is valid 
            }
            return 0;
        }
        
        int include = countSubsequences(index+1,sum + originals[index],originals, k);
        int exclude = countSubsequences(index+1,sum,originals,k);
        return include+exclude;
    }
	public static void main(String[] args) {
		int nums[]={4,9,2,5,1};
		int k=10;
		System.out.println(countSubsequences(0,0,nums,k));
	}
}