class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();


        unordered_map<int,int>mp;
        for(int i=0; i<size; i++){
            int complement=target-nums[i];

            if(mp.find(complement)!=mp.end()){
                return {mp[complement],i};
            }

            mp[nums[i]]=i;
        }

        return {};
    }
};