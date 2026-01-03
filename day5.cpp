#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        vector<int> temp;
        for (int i = size - k; i < size; i++) {
            temp.push_back(nums[i]);
        }

        for (int i = size - 1; i >= 0; i--) {
            if (i - k >= 0) {
                nums[i] = nums[i - k];
            }
        }

        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

int main() {
    int n, k;
    cin >> n;          // size of array
    cin >> k;          // number of rotations

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    obj.rotate(nums, k);

    // print rotated array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
