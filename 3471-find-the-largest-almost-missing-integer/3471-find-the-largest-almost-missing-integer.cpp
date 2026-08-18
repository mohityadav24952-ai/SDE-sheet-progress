class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k == n
        // Pure array mein sirf 1 hi subarray hai, sabse bada element answer hoga.
        if (k == n) {
            int maxi = -1;
            return *max_element(nums.begin() , nums.end());
        }
        
        // Direct fixed-size array/vector since nums[i] <= 50
        vector<int> freq(51, 0);
        for (int x : nums) {
            freq[x]++;
        }
        
        // Case 2: k == 1
        // Jo element pure array mein exact 1 baar aaya ho, unme sabse bada max return karo.
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1) return i; // Subse bada element pehle mil jayega
            }
            return -1;
        }
        
        // Case 3: 1 < k < n
        // Sirf first element (nums[0]) aur last element (nums[n-1]) hi 1 subarray mein aate hain.
        int maxi = -1;
        if (freq[nums[0]] == 1) maxi = max(maxi, nums[0]);
        if (freq[nums[n - 1]] == 1) maxi = max(maxi, nums[n - 1]);
        
        return maxi;
    }
};