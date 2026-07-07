class Solution {
public:
    long long sumAndMultiply(int n) {
        string copy=to_string(n);
        long long sum=0;
        long long ans=0;
        for(char c: copy){
            if(c!='0'){
                int digit=c-'0';
                ans=ans*10+digit;
                sum=sum+digit;
            }
        }
        return (long long) ans*sum;
    }
};