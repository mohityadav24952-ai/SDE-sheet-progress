class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double wsum = 0;
        double ans = 0;
        int n = nums.size();
        

        for(int i=0 ; i<k ; i++){
           wsum += nums[i];
        }
        ans = double(wsum/k) ;

        for(int i=k ; i<n ; i++ ){
            wsum += nums[i];
            wsum -= nums[i-k];


            ans = max(ans ,double(wsum/k) );
        }

        return ans;

    }
};