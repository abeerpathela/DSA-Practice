class Solution {
public:
    int helper(int n,vector<int>& dp){
        if(n==0){
            dp[0]=0;
            return 0;
        }
        if(n==1){
            dp[1]=1;
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=helper(n-1,dp)+helper(n-2,dp);
        dp[n]=ans;
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};