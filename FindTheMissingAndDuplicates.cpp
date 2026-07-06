#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> findTheRepeatingAndMissingNumbers(vector<int>&nums){
    vector<int>answer;
    int twice=0;
    int missing=nums.size();
    
    sort(nums.begin(),nums.end());
    
    vector<int>removeDupli;
    
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1]){
            twice=nums[i];
        }
        else if(nums[i]!=nums[i-1]+1){
            missing=nums[i-1]+1;
        }
        else{
            continue;
        }
    }
    
    return {twice,missing};
}

int main()
{
    vector<int>nums={1, 2, 3, 6, 7, 5, 7};
    
    vector<int> ans=findTheRepeatingAndMissingNumbers(nums);
    
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    
    return 0;
}