class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>result(nums.size());
        int positiveIndex=0;
        int negitiveIndex=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                result[positiveIndex]=nums[i];
                positiveIndex+=2;
            }
            else{
                result[negitiveIndex]=nums[i];
                negitiveIndex+=2;
            }
        }

        return result;
    }
};