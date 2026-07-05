class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size=nums.size();

        int currentCount=0;
        int maxCount=0;

        for(int i=0 ;i<size; i++){
            if(nums[i]==1){
                currentCount++;
                maxCount=max(currentCount,maxCount);
            }
            else{
                currentCount=0;
            }
        }

        maxCount=max(currentCount,maxCount);

        return maxCount;
    }
};