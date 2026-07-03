class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int>given=nums;
        sort(given.begin(),given.end());

        int size=nums.size();
        int currentLength=1;
        int maxLength=1;

        for(int i=1; i<size; i++){
            if(given[i]==given[i-1]){
                continue;
            }
            else if(given[i]==given[i-1]+1){
                currentLength++;
            }
            else{
                maxLength=max(currentLength,maxLength);
                currentLength=1;
            }
        }

        maxLength=max(currentLength,maxLength);

        return maxLength;
    }
};