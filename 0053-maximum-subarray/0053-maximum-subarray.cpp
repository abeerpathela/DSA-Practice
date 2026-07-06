class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixSum(nums.size());

        prefixSum[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        int maxSum=nums[0];
        int minSum=0;

        for(int i=0; i<nums.size(); i++){
            maxSum=max(maxSum,prefixSum[i]-minSum);
            minSum=min(minSum,prefixSum[i]);
        }

        return maxSum;
    }
};