class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int cursum = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;

        for(int i=0 ; i<n ; i++){
            cursum = max(cursum+nums[i],nums[i]);
            maxsum = max(maxsum , cursum);
        }

        cursum =0;
 
        for(int i=0 ; i<n ; i++){
            cursum = min(cursum+nums[i],nums[i]);
            minsum = min(minsum , cursum);
        }

        return max(abs(minsum),abs(maxsum));

    }
};