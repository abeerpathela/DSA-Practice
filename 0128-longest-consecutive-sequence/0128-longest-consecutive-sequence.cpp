class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0){
            return 0;
        }

        int maxLength=1;
        int currentLength=1;

        vector<int>given=nums;
        sort(given.begin(),given.end());

        for(int i=1; i<given.size(); i++){
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