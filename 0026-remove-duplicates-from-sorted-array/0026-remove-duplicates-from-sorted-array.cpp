class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();

        int i=1;
        for(int j=1; j<size; j++){
            if(nums[j]!=nums[j-1]){
                nums[i]=nums[j];
                i++;
            }
        }

        return i;
    }
};