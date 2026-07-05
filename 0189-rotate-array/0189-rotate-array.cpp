class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;

        vector<int>temp;

        for(int i=size-k; i<size; i++){
            temp.push_back(nums[i]);
        }

        for(int i=size-1; i>=0; i--){
            if(i-k>=0){
                nums[i]=nums[i-k];
            }
        }

        for(int i=0; i<k; i++){
            nums[i]=temp[i];
        }
    }
};