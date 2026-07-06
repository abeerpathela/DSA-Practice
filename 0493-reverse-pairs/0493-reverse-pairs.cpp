class Solution {
public:
    int count = 0;

    void merge(vector<int>& nums, int low, int mid, int high) {

        int j = mid + 1;

        // Count reverse pairs
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j])
                j++;

            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid)
            temp.push_back(nums[left++]);

        while (right <= high)
            temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
    }

    void mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return count;
    }
};