#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int j = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        while (j < size) {
            nums[j] = 0;
            j++;
        }
    }
};

int main() {
    int n;
    cin >> n;          // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    obj.moveZeroes(nums);

    // print array after moving zeroes
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
