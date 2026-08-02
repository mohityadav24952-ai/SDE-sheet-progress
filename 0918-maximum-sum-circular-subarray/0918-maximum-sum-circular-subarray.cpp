class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tsum = nums[0];
        int csum = nums[0];
        int maxs = nums[0];
        int mins = nums[0];
        int cmaxsum = 0;
        int n = nums.size();

        for(int i=1;i<n ; i++){
            tsum +=nums[i];
            csum = max(nums[i],csum+nums[i]);
            maxs = max(maxs , csum);
        }
        
        csum = nums[0];

        for(int i=1;i<n ; i++){
           
            csum = min(nums[i],csum+nums[i]);
            mins = min(mins , csum);
        }

        // MIKE KI TRICK YA OBS 

        cmaxsum = tsum - mins;

        if(maxs > 0) return max(cmaxsum , maxs);
        return maxs;


    }
};