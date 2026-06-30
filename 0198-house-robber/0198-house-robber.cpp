class Solution {
public:
    // int solveUsingRecursion(vector<int>& nums, int index){
    //     if(index>=nums.size()){
    //         return 0;
    //     }
    //     int include=nums[index]+solveUsingRecursion(nums,index+2);
    //     int exclude=0+solveUsingRecursion(nums,index+1);
    //     int ans=max(include,exclude);
    //     return ans;
    // }

    // 1 D type dp problem 

    int solveUsingMem(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int include=nums[index]+solveUsingMem(nums,index+2,dp);
        int exclude=0+solveUsingMem(nums,index+1,dp);
        int ans=max(include,exclude);
        dp[index]=ans;
        return dp[index];
    }

    int solveUsingTabulation(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,-1);

        dp[n]=0;
        
        for(int i=n-1; i>=0; i--){
            int temp=0;
            if(i+2 <= n){
                temp=dp[i+2];
            }
            int include=nums[i]+temp;
            int exclude=0+dp[i+1];
            dp[i]=max(include,exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
       int index=0;
       vector<int>dp(nums.size()+1,-1);
       int ans=solveUsingTabulation(nums);
       return ans;
    }
};