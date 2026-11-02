class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 1. Median find karne ke liye array ko sort karein
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // 2. Middle index sidhe n/2 se mil jayega, odd/even dono ke liye yahi median index hota hai
        int mid = n / 2; 
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - nums[mid]);
        }
        
        return ans;
    }
};