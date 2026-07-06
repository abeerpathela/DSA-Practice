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


        // Sort the intervals by their start time.
        // Push the first interval into ans.

        // For every next interval:
        // Compare current interval's start (intervals[i][0]) with last merged interval's end (ans.back()[1]).

        // If current start <= last end, they overlap → update the last end:

        // ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        // Otherwise, there is no overlap → push the current interval into ans.


        // Return ans
    }
};