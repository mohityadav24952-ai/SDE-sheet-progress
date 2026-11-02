class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0 , r=0;
        int z=0;
        int o =0;

        int ans =0;

        while(r<n){

            if(nums[r]==1){
                o++;
            }
            else z++;


            while(z>k){
               
                if(nums[l]==1)o--;
                else z--;
                l++;



            }

            ans = max(ans , z+o);

            r++;


        }

        

        return ans;
    }
};