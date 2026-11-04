class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int lsum = 0;
        int rsum =0;
        int ans = -1;
        int tsum =0;

         tsum = accumulate(nums.begin(),nums.end(),0);
       

        for(int i=0 ; i<n ; i++){
            lsum += nums[i];
           rsum = tsum - lsum + nums[i];

            if(lsum == rsum){
                return i;
            }
        }
        return ans;
    }
};