class Solution {
    static long mod=1000000007;

    private long power(long x, long n){
        long result=1;

        while(n>0){
            if((n%2)==1){
                result=(result*x)%mod;
            }
            x=(x*x)%mod;
            n=n/2;
        }

        return result;
    }
    
    public int countGoodNumbers(long n) {
          long evenCount= (n+1)/2;
          long oddCount= n/2;

           long part1=power(5,evenCount);
           long part2=power(4,oddCount);

          return (int)  ((part1*part2)%mod);      
    }
}