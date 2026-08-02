class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxsubsum = nums[0];
        int minsubsum = nums[0];
        int currsum = nums[0];

        for(int i=1 ; i<n ; i++){

            currsum = max(nums[i],currsum + nums[i]);
            maxsubsum = max(maxsubsum , currsum);

        }
        currsum = nums[0];

        for(int i=1 ; i<n ; i++){

            currsum = min(nums[i],currsum + nums[i]);
            minsubsum = min(minsubsum , currsum);
            
        }

        return max(abs(maxsubsum),abs(minsubsum));

    }
};