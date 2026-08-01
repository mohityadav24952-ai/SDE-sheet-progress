class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

           int sum = 0;
       int ans = 0;
       int rem = 0;
       unordered_map<int,int>mp ;  // prefix sum and count 
        int n = nums.size();
       mp[0]=1;

       for(int i=0 ; i<n ; i++){
           sum += nums[i]%2;

           rem = sum - k ;

           if(mp.find(rem)!=mp.end()){
              ans += mp[rem];
           }

           mp[sum]++;
       }
       return ans ;


    }
};