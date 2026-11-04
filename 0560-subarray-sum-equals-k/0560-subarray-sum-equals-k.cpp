class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int l=0 , r=0;
        int psum=0;
        mp[0]=1;
        int cnt =0;

        while(r<n){

         psum += nums[r];

         if(mp.find(psum-k)!=mp.end()){
            cnt += mp[psum-k];
         }

         mp[psum]++;



            r++;
        }
        return cnt;
    }
};