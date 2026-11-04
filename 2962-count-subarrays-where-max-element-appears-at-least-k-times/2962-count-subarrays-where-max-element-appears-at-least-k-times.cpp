class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();

        long long ans =0;
        int cnt =0;

        long long l=0 , r=0;

        long long maxi = *max_element(nums.begin(),nums.end());

        while(r<n){

            if(nums[r]==maxi) cnt++;

            while(cnt==k){
                  ans += n-r;

                  if(nums[l]==maxi)cnt--;

                  l++;
            }

           


            r++;
        }

        return ans;
    }
};