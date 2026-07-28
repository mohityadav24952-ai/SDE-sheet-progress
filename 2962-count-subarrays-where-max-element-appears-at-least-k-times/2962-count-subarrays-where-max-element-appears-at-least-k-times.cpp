class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int cnt = 0;
        int i = 0 ; int j= 0;
        int n= nums.size();
        int maxe = *max_element(nums.begin() , nums.end());

        while(j<n){
            if(nums[j] == maxe ) cnt++;

            while(cnt >= k){
                ans += n-j;
                if(nums[i] == maxe){
                    cnt--;
                }
                i++;
            }
            j++;

        }
        return 1LL*ans ;


    }
};