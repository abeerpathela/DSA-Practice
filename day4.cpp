#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int i = 1;

        for (int j = 1; j < size; j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    int n;
    cin >> n;               // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];     // sorted array input
    }

    Solution obj;
    int k = obj.removeDuplicates(nums);

    // print unique elements
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
