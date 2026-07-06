class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= ans.back()[1]){  // intervals wale mei se start ko compare kiya hai aur ans wale mei se last wale mei se end ko 
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;



    }
};