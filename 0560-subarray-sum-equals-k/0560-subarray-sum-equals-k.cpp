class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size()==0){
            return 0;
        }

        int size=nums.size();
        
        vector<int>prefixSum(size,0);
        prefixSum[0]=nums[0];

        for(int i=1; i<size; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        int count=0;
        unordered_map<int,int>mp;
        for(int j=0; j<size; j++){
            if(prefixSum[j]==k){
                count++;
            }
            int val=prefixSum[j]-k;

            if(mp.find(val)==mp.end()){
                mp[val]=0;
            }
            else if(mp.find(val)!=mp.end()){
                count=count+mp[val];
            }
            mp[prefixSum[j]]++;
        }
        return count;
    }
};