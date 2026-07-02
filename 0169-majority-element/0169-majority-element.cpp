class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int maxFreq=0;
        int maxEle=0;

        for(auto it: mp){
            if(it.second>maxFreq){
                maxFreq=it.second;
                maxEle=it.first;
            }
        }

        return maxEle;
    }
};