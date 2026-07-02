class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveIndex=0;
        int negitiveIndex=1;

        vector<int> result(nums.size());

        for(int num: nums){
            if(num>=0){
                result[positiveIndex]=num;
                positiveIndex+=2;
            }
            else{
                result[negitiveIndex]=num;
                negitiveIndex+=2;
            }
        }

        return result;
    }
};