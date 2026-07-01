class Solution {
public:
    int solveUsingMem(vector<int>& arr,int curr,int prev,vector<vector<int>>& dp){
        if(curr>=arr.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int include=0;
        if(prev == -1 || arr[curr]>arr[prev]){
            include=1+solveUsingMem(arr,curr+1,curr,dp);
        }
        int exclude=solveUsingMem(arr,curr+1,prev,dp);
        int finalAns=max(include,exclude);
        dp[curr][prev+1]=finalAns;
        return dp[curr][prev+1];
    }
    int solveUsingRec(vector<int>& arr, int curr, int prev){
        // base case 
        if(curr>=arr.size()){
            return 0;
        }

        int include=0;
        if(prev == -1 || arr[curr]>arr[prev]){
            include=1+solveUsingRec(arr,curr+1,curr);
        }
        int exclude=0+solveUsingRec(arr,curr+1,prev);
        int finalAns=max(include,exclude);
        return finalAns;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;

        int n=nums.size();

        // STEP 1 AS this question requires 2 parameters to be changed in the recurrsion call so this question is of 2d type dp problem based 

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        // int ans=solveUsingRec(nums,curr,prev);
        int ans=solveUsingMem(nums,curr,prev,dp);
        return ans;
    }
};