#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> given = nums;
        sort(given.begin(), given.end());

        int currentLength = 1;
        int maxLength = 1;

        for(int i = 1; i < given.size(); i++){
            if(given[i] == given[i-1]){
                continue;
            }
            if(given[i] == given[i-1] + 1){
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        return max(maxLength, currentLength);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.longestConsecutive(nums);

    return 0;
}
