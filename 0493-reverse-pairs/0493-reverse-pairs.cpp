class Solution {
public:

    // ---------------------------------------------------------
    // Merge two sorted halves
    // ---------------------------------------------------------
    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        // Merge both sorted halves
        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining elements of left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Remaining elements of right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back into original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // ---------------------------------------------------------
    // Count reverse pairs between left and right sorted halves
    // ---------------------------------------------------------
    int countPairs(vector<int>& nums, int low, int mid, int high) {

        int right = mid + 1;
        int cnt = 0;

        // Traverse every element of left half
        for (int i = low; i <= mid; i++) {

            // Move right pointer until condition is satisfied
            while (right <= high &&
                   (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }

            // Elements from (mid+1) to (right-1)
            // form reverse pairs with nums[i]
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    // ---------------------------------------------------------
    // Merge Sort
    // ---------------------------------------------------------
    int mergeSort(vector<int>& nums, int low, int high) {

        // Base case
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        // Count in left half
        cnt += mergeSort(nums, low, mid);

        // Count in right half
        cnt += mergeSort(nums, mid + 1, high);

        // Count cross reverse pairs
        cnt += countPairs(nums, low, mid, high);

        // Merge both sorted halves
        merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};