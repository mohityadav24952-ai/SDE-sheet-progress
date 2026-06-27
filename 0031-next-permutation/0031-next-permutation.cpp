class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // -------------------------------------------------
        // Step 1 : Find the first index from the back where
        // nums[i] < nums[i + 1]
        // This is called the "break point".
        // -------------------------------------------------
        int ind = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // -------------------------------------------------
        // If no break point exists,
        // array is already the largest permutation.
        // Simply reverse to get the smallest permutation.
        // -------------------------------------------------
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // -------------------------------------------------
        // Step 2 : Find the first element from the end
        // which is greater than nums[ind].
        // Swap both.
        // -------------------------------------------------
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // -------------------------------------------------
        // Step 3 : Reverse the suffix after the break point.
        // This makes it the smallest possible permutation.
        // -------------------------------------------------
        reverse(nums.begin() + ind + 1, nums.end());
    }
};