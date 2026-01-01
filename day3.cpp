#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int count = 0;

        for (int i = 0; i < size - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }

        if (nums[size - 1] > nums[0]) {
            count++;
        }

        return count <= 1;
    }
};

int main() {
    int n;
    cin >> n;              // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];    // array elements
    }

    Solution obj;
    bool result = obj.check(nums);

    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}
