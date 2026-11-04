class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        

        int n = nums.size();
        int maxs = *max_element(nums.begin(),nums.end());
        int s=0;


        for(int i=0 ; i<n ; i++){
             s += nums[i];
             maxs = max(maxs,s);
             if(s<0) s=0;
        }

        int mins = *min_element(nums.begin(),nums.end());

        int cursum =0;
       
        for(int i=0 ; i<n ; i++){

            cursum = min(nums[i],cursum+nums[i]);
            mins= min(mins,cursum);

        }

        int tsum = accumulate(nums.begin(),nums.end(),0);

        int maxcsum = tsum - mins;

        if(maxs<0) return maxs;
        return max(maxs,maxcsum);

    }
};