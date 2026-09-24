class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int digitSum = 0;
            int temp = nums[i];
            
            // Calculate the sum of the digits
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            
            // Check if the sum equals the index
            if (digitSum == i) {
                return i;
            }
        }
        
        // If no such index is found
        return -1;
    }
};