class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n==0){
            return;
        }

        vector<int>answer;

        int i=0; 
        int j=0;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                answer.push_back(nums1[i]);
                i++;
            }
            else{
                answer.push_back(nums2[j]);
                j++;
            }
        }

        if(i<m){
            while(i<m){
                if(nums1[i]==0){
                    i++;
                }
                else{
                    answer.push_back(nums1[i]);
                    i++;
                }
            }
        }

        if(j<n){
            while(j<n){
                    answer.push_back(nums2[j]);
                    j++;
            }
        }

        for(int i=0; i<answer.size();i++){
            nums1[i]=answer[i];
        }
    }
};