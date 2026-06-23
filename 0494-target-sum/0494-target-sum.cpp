class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        // Total sum of array
        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }

        // Impossible cases
        if(abs(target) > total || (total + target) % 2 != 0){
            return 0;
        }

        // Required subset sum
        int sum = (total + target) / 2;

        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));        // LEARN THISSSSSSS WAYYY

        // Base cases
        t[0][0] = 1;

        for(int i = 1; i <= n; i++){
            t[i][0] = 1;
        }

        // Count subsets having sum = sum
        for(int i = 1; i <= n; i++){

            for(int j = 0; j <= sum; j++){

                // Pick + Not Pick
                if(nums[i - 1] <= j){
                    t[i][j] = t[i - 1][j] +
                              t[i - 1][j - nums[i - 1]];
                }
                else{
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};