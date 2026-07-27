class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxx =0 ;
        int smax = 0;

        for(int i=0 ; i<n ; i++){
        if(nums[i] > maxx){
            smax = maxx ;
            maxx = nums[i];
        }
        else if ( nums[i] > smax){
            smax = nums[i];
        }

        }

        return (maxx-1)*(smax-1);
    }
};