class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // Answer array
        vector<int> ans(n);

        // -------------------------------
        // PASS 1 : Store Prefix Products
        // -------------------------------

        // Prefix product before index 0 is always 1
        ans[0] = 1;

        // ans[i] = product of all elements before i
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // -------------------------------
        // PASS 2 : Multiply by Suffix Products
        // -------------------------------

        // Suffix product after last index is 1
        int suffix = 1;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Multiply current prefix with current suffix
            ans[i] *= suffix;

            // Update suffix for next iteration
            suffix *= nums[i];
        }

        return ans;
    }
};