class Solution {
public:
    int usingRecurrsion(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        int mini=INT_MAX;

        for(int i=0; i<coins.size(); i++){
            if(coins[i]<=amount){
                // valid case 
                int recurrsionAns=usingRecurrsion(coins,amount-coins[i]);
                if(recurrsionAns!=INT_MAX){
                    mini=min(mini,1+recurrsionAns);
                }
            }
        }
        return mini; 
    }
    int usingMem(vector<int>& coins,int amount,vector<int>& dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }


        int mini=INT_MAX;

        for(int i=0; i<coins.size(); i++){
            if(coins[i]<=amount){
                // valid case 
                int recurrsionAns=usingMem(coins,amount-coins[i],dp);
                if(recurrsionAns!=INT_MAX){
                    mini=min(mini,1+recurrsionAns);
                }
            }
        }
        dp[amount]=mini;
        return dp[amount]; 
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=amount;
        vector<int>dp(n+1,-1);
        int ans=usingMem(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};