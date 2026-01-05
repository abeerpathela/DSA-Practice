#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int i = 0;

        for (int j = 0; j < size; j++) {
            if (nums[j] != i) {
                return i;
            }
            i++;
        }
        return nums.size();
    }
};

int main() {
    int n;
    cin >> n;           // size of array (n numbers from 0 to n)

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int missing = obj.missingNumber(nums);

    cout << missing;

    return 0;
}
