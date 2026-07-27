class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
     unordered_set<int>st ;
     int n = nums.size();
     int i = 0;
     int j= 0;
     long long ans = 0;
     long long  cursum = 0;


     while(j<n){
        

        while(st.count(nums[j]) !=0 ){
            cursum -= nums[i];
            st.erase(nums[i]);
            i++;
        }

        cursum += nums[j];
         st.insert(nums[j]);

        if(j-i+1 == k){
            ans = max(ans,cursum);
            cursum -= nums[i];
            st.erase(nums[i]);
            i++;
        }
        

        j++;
     }
      return ans ;
        
    }
};