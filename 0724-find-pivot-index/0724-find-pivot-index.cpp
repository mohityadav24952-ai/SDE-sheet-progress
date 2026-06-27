class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        // Step 1: Find total sum of the array
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Left side sum initially 0
        int leftSum = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Right sum = Total Sum - Left Sum - Current Element
            int rightSum = totalSum - leftSum - nums[i];

            // If both sums are equal, current index is the pivot
            if (leftSum == rightSum) {
                return i;
            }

            // Include current element in left sum
            leftSum += nums[i];
        }

        // No pivot index found
        return -1;
    }
};