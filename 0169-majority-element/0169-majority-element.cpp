class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();

        int count=0;
        int candidate=nums[0];

        int i=0;
        while(i<size){
            if(count==0){
                candidate=nums[i];
                count=1;
            }
            else{
                count = count + (candidate == nums[i] ? 1 : -1);
            }
            i++;
        }
        return candidate;
    }
};